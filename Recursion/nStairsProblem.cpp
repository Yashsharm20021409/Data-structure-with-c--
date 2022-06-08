// in code studio it can be done only by dp but this code is correct for recursion only
// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10&leftPanelTab=0
int countDistinctWayToClimbStair(long long nStairs)
{
    //  base case
    if(nStairs<0){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }
    else{
        return countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs-2);
    }
}