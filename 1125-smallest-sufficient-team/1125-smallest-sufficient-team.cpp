class Solution {
public:
    vector<vector<int>> memo;
   map<string,int> index;
int dp(int mask,int person,int allmask,vector<int> people)
{
    if(mask==allmask)
        return 0;
    if(person>=people.size())
        return 62;
    if(memo[mask][person]!=-1)
        return memo[mask][person];
    int q=min(1+dp(mask|people[person],person+1,allmask,people),dp(mask,person+1,allmask,people));
    return memo[mask][person]=q;
}
vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& p) 
{
    vector<int> people(p.size(),0);
    int allmask=(1<<req_skills.size())-1;
    memo.resize(allmask, vector<int>(people.size(), -1));
    for(int i=0;i<req_skills.size();++i)
        index[req_skills[i]]=i;
    for(int i=0;i<p.size();++i)
    {
        int mask=0;
        for(string skill:p[i])
            mask=mask|1<<index[skill];
        people[i]=mask;
    }
    vector<int> ret;
    int val=dp(0,0,allmask,people);
    int mask=0;
    for(int person=0;person<people.size();++person)
    {
        int temp=mask;
        if(memo[mask][person]>val)
        {
            mask=mask|people[person-1];
            ret.push_back(person-1);
            val--;
        }
        if(person==people.size()-1)
            if(mask!=allmask&&mask|people[person]==allmask)
                ret.push_back(person);
        if(val==0)
            break;
    }
    return ret;
}
};