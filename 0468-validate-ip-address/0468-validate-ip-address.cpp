class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
    
    bool isIPv4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) return false;

        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) return false;
        
        for (auto part : parts) {
            if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) return false;
            for (char c : part) {
                if (!isdigit(c)) return false;
            }
            if (stoi(part) > 255) return false;
        }
        
        return true;
    }
    
    
    bool isIPv6(string IP) {
        transform(IP.begin(), IP.end(), IP.begin(), ::toupper);
        if (count(IP.begin(), IP.end(), ':') != 7) return false;
        
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) return false;
        
        for (auto part : parts) {
            if (part.empty() || part.size() > 4) return false;
            for (auto c : part) {
                if (!isdigit(c) && (c < 'A' || c > 'F')) return false;
            }
        }
        
        return true;
    } 
    
    
    vector<string> split(string query, char op) {
        vector<string> parts;
        
        stringstream ss(query);
        string part;
        while (getline(ss, part, op)) {
            parts.push_back(part);
        }
        
        return parts;
    }
};