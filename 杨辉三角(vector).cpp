class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> vv;
        
        //开辟杨辉三角
        vv.resize(numRows);
        for(size_t i = 1;i<=numRows;++i)
        {
            vv[i-1].resize(i,0);
            
            //把每一行的第一个和最后一个都置为1
            vv[i-1][0]=1;
            vv[i-1][i-1]=1;
        }
        
        //进行赋值，构建杨辉三角
        for(size_t i = 0;i<vv.size();++i)
        {
            for(size_t j =0;j<vv[i].size();++j)
            {
                if(vv[i][j] == 0)
                {
                    vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
                }
            }
        }
        return vv;
    }
};
