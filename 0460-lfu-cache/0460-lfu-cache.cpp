class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyVal; // stores {key,{val,freq}}
    unordered_map<int, list<int>> freqList; // stores {freq,{list of keys with this freq}}
    unordered_map<int, list<int>::iterator> pos; // stores {key,list iterator holding this key in list} (so we can delete key from list in O(1) time)

    void updateFreq(int key){
        int curr_freq=keyVal[key].second;
        freqList[curr_freq].erase(pos[key]); // delete key from old freq bucket

        keyVal[key].second++; // increment freq 
        curr_freq=keyVal[key].second;

        freqList[curr_freq].push_back(key); // insert key in new freq
        pos[key]=--freqList[curr_freq].end(); // update new pos of key

        if(freqList[minFreq].size()==0) minFreq++; // check for minFreq 
    }

    LFUCache(int c) {
        capacity=c;
        minFreq=0;
    }
    
    int get(int key) {
        if(keyVal.count(key)==0) return -1;

        updateFreq(key);
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;

        if(keyVal.count(key)>0){ // key already exists, update to new value
            keyVal[key].first=value;

            updateFreq(key);
            return;
        }

        if(keyVal.size()==capacity){
            int delKey=freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }

        // new key-val insert
        keyVal[key]={value,1};
        freqList[1].push_back(key);
        pos[key]=--freqList[1].end();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */