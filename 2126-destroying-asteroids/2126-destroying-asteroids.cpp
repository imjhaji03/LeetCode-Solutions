class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long new_mass = mass;
        for(int i = 0; i < n; i++){
            if(new_mass < asteroids[i]){
                return false;
            }
            new_mass += asteroids[i];
        }
        return true;
        
    }
};