class TimeMap {
    unordered_map<string, vector<pair<string, int>>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string to_return = "";
        int s = 0, e = timemap[key].size()-1;
        while (s<=e) {
            int mid = s+(e-s)/2;
            if (timemap[key][mid].second == timestamp) return timemap[key][mid].first;
            if (timemap[key][mid].second < timestamp) {
                to_return = timemap[key][mid].first;
                s = mid+1;
            }
            else e = mid-1;
        }
        return to_return;
    }
};
