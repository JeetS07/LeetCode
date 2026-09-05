class Solution {
public:
    int m,n;
    int target_mask;
    vector<int> result;

    unordered_map<string,int> dp;

    void solve(vector<int> &people_skill, int i, vector<int> &temp, int mask){
        if(i==m){ 
            if(mask==target_mask){ // answer candidate
                if(result.size()==0 || temp.size()<result.size()) result=temp; // preserving smallest answer
            }
            return;
        }

        string key = to_string(i) + "_" + to_string(mask);
        if(dp.count(key)!=0){
            if(dp[key]<=temp.size()) return;
        }

        if(result.size()!=0 && result.size()<=temp.size()) return; // to avoid unnecessary recursive stacks

        // not take
        solve(people_skill, i+1, temp, mask);

        // take
        if(mask|people_skill[i] != mask){ // mask|people_skill[i] == mask means we are adding an employee with zero skill(000)
            temp.push_back(i);
            solve(people_skill, i+1, temp, (mask | people_skill[i]));
            temp.pop_back(); // backtracking

        }
        
        dp[key] = (temp.size()!=0) ? temp.size() : -1;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n=req_skills.size();
        m=people.size();

        unordered_map<string,int> skills;

        for(int i=0;i<n;i++) skills[req_skills[i]]=i; // assigning unique bit position to skills

        vector<int> people_skill;
        for(auto &i:people){ // converting people(in string) to people_skill(in int)
            int skill_bit=0;
            for(string &skill:i) skill_bit=skill_bit | (1 << skills[skill]);

            people_skill.push_back(skill_bit);
        }

        target_mask=pow(2,n)-1;
        vector<int> temp;

        solve(people_skill,0,temp,0);
        return result;
    }
};

// Recusrion, Bitmask

// applying normal recusrion (take and not take for every people)
// only challenge is if we use people's skills in string form we will get MLE
// so if total n skills are there, we assign a bit for every skill in n-bit binary
// eg.: java, python, cpp -> 3 skills will be represented in 000 binary form
// java-0th bit
// python-1th bit
// cpp-2th bit
// now 001 represent only java is found
//     ...
//     111 represent all skills are found 
// starting bit 000(no skills), target bit 111(all skills)
// to append a new skill to existing skillset we do OR operation
// eg.: existing skill 001, need to append 010 -> 001|010 = 011
// now using recursion we find the lowest people size when target mask is reached