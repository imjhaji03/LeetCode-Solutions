class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i=0;
    
    while(i<seats.size() and seats[i]!=0)
    {
        i++;
    }
    
    int maxd=0;
    
    int s=-1;
    
    while(i<seats.size())
    {
        
        s=i;
        int count=0;
        
        while(i<seats.size() and seats[i]==0)
        {
            count++;
            i++;
        }
        
        int empty=i-s;
            
        if(s==0 or i==seats.size())
        maxd=max(maxd,empty);
        
        maxd=max(maxd,(empty+1)/2);
        
        while(i<seats.size() and seats[i]!=0)
        {
            i++;
        }
    
    }
    
    return maxd;
    }
};