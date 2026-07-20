class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(auto str : strs){
            for(auto c : str){
                int code = c % 256;
                if(code < 10){
                    output += "00" + to_string(c);
                } else if (code < 100) {
                    output += "0" + to_string(c);
                } else {
                    output += to_string(c);
                }
            }
            output += ",,,";
        }
        return output;
    }

    vector<string> decode(string s) {
        int inSize = s.size();
        int txtSize = inSize/3;
        vector<string> output;
        string word="";
        for(int i = 0; i < inSize; i += 3){
            string charr = s.substr(i, 3);
            int ascii = 0;
            if(charr == ",,,"){
                output.push_back(word);
                word = "";
                ascii = 0;
            }
            else{
                ascii += (stoi(charr));
                word += char(ascii);
            }
        }
        return output;
    }
};
