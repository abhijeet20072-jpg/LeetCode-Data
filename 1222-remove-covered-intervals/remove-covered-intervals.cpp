class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int c=1;
        int s=intervals[0][0];
        int e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]==s){
                e=max(e,intervals[i][1]);
            }
            else if(intervals[i][0]>s&&intervals[i][1]<=e){
                continue;
            }
            else if(intervals[i][0]>s&&intervals[i][1]>e){
                c++;
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else if(intervals[i][0]>=e){
                c++;
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        return c;
    }
};