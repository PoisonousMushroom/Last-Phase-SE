/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
#include <gtest/gtest.h>
#include "../headers/world.h"

TEST(WorldTest, testLoad){
    World w;
    EXPECT_EQ(0, w.load("map.txt"));
    EXPECT_EQ(0, w.cell_test());
    w.print_grid();
}

TEST(WorldTest, testAdj){
    World w;
    aux::tposition p;
    aux::tposition res;
    int count = 0;
    p.x = 3;
    p.y = 3;
    aux::tdirection t;
    for(int i = 0; i< 6; i++){
        t.d = i;
        res = w.adjacent(t, p);
        if(res.x == -1){
            throw Exception("Adjacent test failed! \n");
        }
        else{
            count++;
        }
    }
    EXPECT_EQ(6, count);
}
TEST(WorldTest, testBugCount){
    World w;
    w.load("map.txt");
    cout << "Cell size: " << w.get_cellcont().size() << " " << w.get_cellcont()[0].size() << endl;
    cout << "Black bug count: " << w.black_count() << endl;
    cout << "Red bug count: " << w.red_count() << endl;
    w.get_blackbugs()[0]->set_has_food(true);
    w.get_blackbugs()[5]->set_has_food(true);
    w.get_blackbugs()[4]->set_has_food(true);
    w.get_blackbugs()[1]->set_has_food(true);
    w.get_blackbugs()[2]->set_has_food(true);
    w.get_blackbugs()[3]->set_has_food(true);
    
    EXPECT_EQ(1, w.get_blackbugs()[0]->get_has_food());
    EXPECT_EQ(1, w.get_blackbugs()[1]->get_has_food());
    EXPECT_EQ(6, w.black_food());
}
 * */
