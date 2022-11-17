class Solution {
  int OverlapLength(int A, int C, int E, int G)
    {
        if(C < E || A > G)
            return 0;
        return min(C, G) - max(A, E);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
       
    int abcd = (A-C)*(B-D);
    int efgh = (E-G)*(F-H);
    
    int common = OverlapLength(A, C, E, G) * OverlapLength(B, D, F, H);
        
    return abcd + efgh - common;



/*
    ACEG => 0
    ACEG => CE
    AECG => EC
    EACG => AC
    EAGC => AG
    EGAC => 0
*/

    }
};