class Solution {
public:
    void findWinner(vector<int> &persons, int k, int idx) {
        if (persons.size() == 1)
            return;
        int kill=(idx+k-1)%persons.size();
        persons.erase(persons.begin()+kill);
        findWinner(persons,k,kill);
        
    }

    int findTheWinner(int n, int k) {
        vector<int> persons(n, 0);
        for (int i = 0; i < n; i++) {
            persons[i] = i + 1;
        }
        findWinner(persons, k, 0);
        return persons[0];
    }
};