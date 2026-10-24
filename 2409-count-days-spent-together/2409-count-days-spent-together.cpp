class Solution {
public:
    int aAM,aAD,aLM,aLD,bAM,bAD,bLM,bLD;

    bool isCommon(int &d, int &m) {
        bool alice = ((m>aAM || (m==aAM && d>=aAD)) && (m<aLM || (m==aLM && d<=aLD)));
        bool bob = ((m>bAM || (m==bAM && d>=bAD)) && (m<bLM || (m==bLM && d<=bLD)));

        return alice && bob;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        aAM=stoi(arriveAlice.substr(0,2));
        aAD=stoi(arriveAlice.substr(3,2));
        aLM=stoi(leaveAlice.substr(0,2));
        aLD=stoi(leaveAlice.substr(3,2));

        bAM=stoi(arriveBob.substr(0,2));
        bAD=stoi(arriveBob.substr(3,2));
        bLM=stoi(leaveBob.substr(0,2));
        bLD=stoi(leaveBob.substr(3,2));

        vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
        int ans=0;

        for(int i=0;i<12;i++){
            int month=i+1;

            for(int j=1;j<=days[i];j++){
                if(isCommon(j,month))
                    ans++;
            }
        }

        return ans;
    }
};