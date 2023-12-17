class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineFood; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<cuisines.size();i++){
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineFood[cuisines[i]].insert({(-1*ratings[i]), foods[i]});
        }
}
    
    
    void changeRating(string food, int newRating) {
        auto cuisine = foodCuisine[food];
        auto oldData = cuisineFood[cuisine].find({(-1*foodRating[food]), food});

        cuisineFood[cuisine].erase(oldData);

        cuisineFood[cuisine].insert({(-1*newRating), food});

        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto highestRating = *cuisineFood[cuisine].begin();

        return highestRating.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */