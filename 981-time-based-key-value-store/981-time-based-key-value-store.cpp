// class TimeMap {
// public:    
//     unordered_map<string,map<int,string, greater<int>>>m;
//     TimeMap() {
//     }
    
//     void set(string key, string value, int timestamp) {
//         m[key][timestamp]=value;
//     }
    
//     string get(string key, int timestamp) {
//                 auto p = m[key];
//                 auto ind = p.lower_bound(timestamp);
//                 if(ind == p.end())
//                     return "";
//                 return ind->second;
//     }
// };

class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        auto &v = mp[key];
        
        auto itm = v.lower_bound(timestamp);
        if(itm == v.end()) return "";
        
        return itm->second;

    }
};