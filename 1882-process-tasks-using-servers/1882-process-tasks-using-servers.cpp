class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> freeServers;
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) { 
            freeServers.push({servers[i], i}); 
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { //
            //Move busy servers to free servers if they are free by ith time
            //Busy Servers to Free Servers
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            //Free Server to Busy Server
            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else {
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }

        return result;
    }
};
