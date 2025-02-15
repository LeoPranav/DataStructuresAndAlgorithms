#include<bits/stdc++.h>
using namespace std;
#define int long long 


map<string,vector<vector<string>>> dp;

// bool canSum(int target,vector<int> nums)
// {
//     if(target==0)
//         return true;

//     if(target<0)
//         return false;

//     if(dp.find(target)!=dp.end())
//         return dp[target];

//     bool gud = false;

//     for(auto&it: nums){
//         gud|=canSum(target-it,nums);
//     }

//     return dp[target]=gud;


// }

// vector<int> howSum(int target,vector<int> nums){

//     if(target==0)
//         return {};

//     if(target<0)
//         return{-1};

//     if(dp.find(target)!=dp.end())
//         return dp[target];

//     vector<vector<int>> sol;
//     int sz =INT_MAX;

//     for(auto&it: nums){

//         vector<int> tmp = howSum(target-it,nums);
//         if(tmp.empty() || tmp[0]!=-1)
//         {   
//             tmp.push_back(it);
//             sol.push_back(tmp);
//             sz = min(sz,(int)tmp.size());
//             tmp.pop_back();
//         }
//     }

//     for(auto&it: sol){
//         if(it.size()==sz)
//             return dp[target] = it;
//     }

//     return dp[target]={-1};

// }


// bool canConstruct(string target,vector<string> strings){

//     if(target=="")
//         return true;

//     bool poss = false;

//     if(dp.find(target)!=dp.end())
//         return dp[target];

//     for(auto&it: strings){

//         if((int)it.size()<=(int)target.size()){


//             int len = it.size();
//             string tmp = target.substr(0,len);

//             if(it==tmp){

//                 // if((int)target.size()==(int)it.size()){
//                 //     poss=true;
//                 // }
//                 // else
//                 poss |=canConstruct(target.substr(len),strings);
//             }

//         }

//     }


//     return dp[target]=poss;


// }


// int countConstruct(string target,vector<string> strings )
// {

//     if(target=="")
//         return 1;

//     int count =0;

//     if(dp.find(target)!=dp.end())
//         return dp[target];

//     for(auto&it : strings){

//         int len = it.size();
//         int sz = target.size();

//         if(len<=sz){

//             if(target.substr(0,len)==it){

//                 if(len==sz)
//                     count++;
//                 else
//                     count+=countConstruct(target.substr(len),strings);
//             }

//         }

//     }


//     return dp[target]=count;

// }

// vector<vector<string>> allConstruct(string target,vector<string> strings){

//     // cout<<target<<endl;

//     if(target=="")
//         return{{""}};

//     if(dp.find(target)!=dp.end())
//         return dp[target];

//     vector<vector<string>> sol;

//     for(auto&it: strings){

//         int len = it.size();
//         int sz = target.size();
//         vector<vector<string>> tmp;

//         if(len<=sz){

//             if(target.substr(0,len)==it){

//                 tmp = allConstruct(target.substr(len),strings);

//                 if(tmp.empty() || tmp[0][0]!="-1"){

//                     for(auto&li: tmp){
//                         li.push_back(it);
//                     }
                    
//                     for(auto&li: tmp)
//                         sol.push_back(li);

//                 }

//             }

//         }


//     }

//     if(!sol.empty() && sol[0][0]=="-1")
//         return {{"-1"}};

//     return dp[target]=sol;

// }


int canSumTabulation(int target,vector<int> nums){

    vector<int> dp(target+1,0);
    dp[0]=1;

    for(int i=1;i<=target;i++){

        for(auto&it: nums){
            if(i-it>=0){
                dp[i]|=dp[i-it];
            }
        }

    }

    return dp[target];
}

vector<int> howSumTabulation(int target,vector<int> nums){

    if(target==0)
        return {};

    vector<int> ans={-1};

    vector<vector<int>> dp(target+1,vector<int>(1,-1));
    dp[0] ={};

    for(int i =1;i<=target;i++){

        for(auto&it: nums){

            if(i-it>=0){

                if(dp[i-it]!=ans)
                {
                    dp[i] = dp[i-it];
                    dp[i].push_back(it);
                    break;
                }
            }

        }


    }
    ans = dp[target];
    
    return ans;

}

vector<int> bestSumTabulation(int target,vector<int> nums){

    if(target==0)
        return {};

    vector<vector<int>> dp(target+1,vector<int>(1,-1));

    dp[0] = {};
    vector<int> ans ={-1};
    for(int i=0;i<target;i++){

        if(dp[i]!=ans){

            for(auto&it: nums){

                if(it+i<=target){

                    vector<int> tmp = dp[i];
                    tmp.push_back(it);

                    if(dp[i+it]==ans || (int)tmp.size()<(int)dp[i+it].size()){
                        dp[i+it] =tmp;
                    }

                }

            }

        }

    }

    return dp[target];


}


bool canConstructTabulation(string target,vector<string> strings){

    int sz = target.size();

    vector<int> dp(sz+1,0);
    dp[0] =1;

    for(int i =1;i<=sz;i++){

        for(auto&it : strings){

            int len = it.size();

            if(i-len>=0){
                string tmp = target.substr(i-len,len);
                if(tmp==it){ 
                    dp[i] +=dp[i-len];
                }
            }
        }

    }


    return dp[sz];
}


int countConstructTabulation(string target,vector<string> strings){

    int sz = target.size();

    vector<int> dp(sz+1,0);
    dp[0] =1;

    for(int i =1;i<=sz;i++){

        for(auto&it : strings){

            int len = it.size();

            if(i-len>=0){
                string tmp = target.substr(i-len,len);
                if(tmp==it){ 
                    dp[i] +=dp[i-len];
                }
            }
        }

    }


    return dp[sz];
}


void print(vector<vector<vector<string>>>arr){

    for(int i=0;i<arr.size();i++){

        for(auto&it: arr[i]){
            for(auto&i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

    }

}


vector<vector<string>> allConstructTabulation(string target,vector<string> strings){

    int sz = target.size();
    vector<vector<string>> bad = {{"-1"}};
    vector<vector<vector<string>>> dp(sz+1,bad); 

    dp[0]={{""}};

    for(int i=1;i<=sz;i++){


        for(auto&it: strings){
            int len = it.size();

            if(i-len<0)
                continue;

            if(dp[i-len][0][0]=="-1")
                continue;

            string tmp = target.substr(i-len,len);

            if(tmp!=it)
                continue; 

            if(dp[i][0][0]=="-1")
                dp[i]={};


            for(auto&li: dp[i-len]){
                vector<string> res = li;
                res.push_back(it);
                dp[i].push_back(res);
            }

        }


    }
   

    return dp[sz];
}


signed main()
{ 


    // cout<<canConstructTabulation("abcdef",{"ab","abc","abcd","def","cd"});cout<<endl;
    // cout<<canConstructTabulation("skateboard",{"bo","rd","ate","t","ska","sk","boar"});cout<<endl;
    // cout<<canConstructTabulation("enterapotentpot",{"a","p","ent","enter","ot","o","t"});cout<<endl;
    // cout<<canConstructTabulation("eeeeeeeeeeeeeeeeeeef",{"e","ee","eee","eeee","eeeee","eeeeeee","eeeeeee"});cout<<endl;


    // cout<<countConstructTabulation("abcdef",{"ab","abc","abcd","def","cd"});cout<<endl;
    // cout<<countConstructTabulation("skateboard",{"bo","rd","ate","t","ska","sk","boar"});cout<<endl;
    // cout<<countConstructTabulation("enterapotentpot",{"a","p","ent","enter","ot","o","t"});cout<<endl;
    // cout<<countConstructTabulation("eeeeeeeeeeeeeeeeeeef",{"e","ee","eee","eeee","eeeee","eeeeeee","eeeeeee"});cout<<endl;
    // cout<<countConstructTabulation("purple",{"purpl","purp","p","ur","le"});cout<<endl;


    // auto ans = allConstructTabulation("abcdef",{"ab","abc","abcd","def","cd","ef","c"});

    // for(auto&it: ans){

    //     for(auto&i: it){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    auto ans = allConstructTabulation("purple",{"purp","p","ur","le","purpl"});

    for(auto&it: ans){

        for(auto&i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}




