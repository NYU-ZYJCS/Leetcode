class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (string& passengerInfo : details) {
            int age = stoi(passengerInfo.substr(11, 2));

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};