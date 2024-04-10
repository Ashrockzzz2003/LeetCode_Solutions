class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;

        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        sort(deck.begin(), deck.end());

        vector<int> the_order(deck.size());

        for(int i = 0; i < deck.size(); i++) {
            the_order[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }

        return the_order;
    }
};