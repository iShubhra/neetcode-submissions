class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

    //     for ( int i = 0; i <intervals.size(); i++ ){
    //         cout << "start : " << intervals[i][0] << " end :" << intervals[i][1] << endl;
    //     }

    //    cout << endl;

        int count = 0, start = intervals[0][0], end = intervals[0][1];
        for ( int i = 1; i < intervals.size(); i++ ){
            if ( start == intervals[i][0] && intervals[i][1] > start || intervals[i][0] < end ){
                count++;
            }else{
                start = intervals[i][0];
                end = intervals[i][1];
            }

            //cout << "start : " << start << " end :" << end << " index " << i <<endl;
        }

        return count;
    }
};
