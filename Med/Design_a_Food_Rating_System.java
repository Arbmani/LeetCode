import java.util.*;
/*

Design a food rating system that can do the following:

-   Modify the rating of a food item listed in the system.

-   Return the highest-rated food item for a type of cuisine in the system.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, 
that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], 
then x[i] comes before y[i] in alphabetic order.

*/

//  Implement the FoodRatings class:
class FoodRatings {
    private Map<String, FoodInfo>        foodMap;
    private Map<String, TreeSet<String>> cuisineMap;

    private static class FoodInfo {
        String  cuisine;
        int     rating;

        FoodInfo(String cuisine, int rating) {
            this.cuisine = cuisine;
            this.rating  = rating;
        }
    }


    /**
     * FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. 
     * The food items are described by foods, cuisines and ratings, all of which have a length of n.
     * 
     * @param foods [i] is the name of the ith food,
     * @param cuisines [i] is the type of cuisine of the ith food, and
     * @param ratings [i] is the initial rating of the ith food.
     */
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodMap     = new HashMap<>();
        cuisineMap  = new HashMap<>();

        for (int i = 0; i < foods.length; i++){
            String food     = foods[i];
            String cuisine  = cuisines[i];
            int    rating   = ratings[i];

            foodMap.put(food, new FoodInfo(cuisine, rating));
            cuisineMap.putIfAbsent(cuisine, new TreeSet<>((a, b) -> {
                int ratingA = foodMap.get(a).rating;
                int ratingB = foodMap.get(b).rating;
                if (ratingA != ratingB) return Integer.compare(ratingB, ratingA);
                return a.compareTo(b);
            }));
            cuisineMap.get(cuisine).add(food);
        }


    }
    
    //  void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
    public void changeRating(String food, int newRating) {
        FoodInfo        info  = foodMap.get(food);
        TreeSet<String> foods = cuisineMap.get(info.cuisine); 
        foods.remove(food);
        info.rating = newRating;
        foods.add(food);
    }
    
    //  String highestRated(String cuisine) Returns the name of the food item that has the highest 
    //  rating for the given type of cuisine. If there is a tie, 
    //  return the item with the lexicographically smaller name.
    public String highestRated(String cuisine) {
        return cuisineMap.get(cuisine).first();
    }
}

public class Design_a_Food_Rating_System{
    public static void main(String[] args) {
        String[] foods      = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
        String[] cuisines   = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
        int[] ratings       = {9, 12, 8, 15, 14, 7};


        FoodRatings fr = new FoodRatings(foods, cuisines, ratings);
        System.out.println("\nWant : kimchi\nWas  : " + fr.highestRated("korean"));
        System.out.println("\nWant : ramen\nWas  : " + fr.highestRated("japanese"));
        fr.changeRating("sushi",16);
        System.out.println("\nWant : sushi\nWas  : " + fr.highestRated("japanese"));
        fr.changeRating("ramen",16);
        System.out.println("\nWant : ramen\nWas  : " + fr.highestRated("japanese"));
    }
}

