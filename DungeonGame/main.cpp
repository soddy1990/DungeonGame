//
//  main.cpp
//  DungeonGame
//
//  Created by 黄美强 on 15/4/24.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int travel(int row,int col,vector<vector<int> > &dungeon,int rows,int cols,int minimum,int current){
    if(row == rows - 1 && col == cols - 1){
        current += dungeon[row][col];
        if(current<=0){
            minimum += 0 - current +1;
            current = 1;
        }
        return minimum;
    }
    else if(row == rows - 1){
        current += dungeon[row][col];
        if(current<=0){
            minimum += 0 - current +1;
            current = 1;
        }
        return travel(row,col+1,dungeon,rows,cols,minimum,current);
    }
    else if(col == cols - 1){
        current += dungeon[row][col];
        if(current<=0){
            minimum += 0 - current +1;
            current = 1;
        }
        return travel(row+1,col,dungeon,rows,cols,minimum,current);
    }
    else{
        current += dungeon[row][col];
        if(current<=0){
            minimum += 0 - current +1;
            current = 1;
        }
        
        int current_r = current + dungeon[row][col+1];
        int minimum_r = minimum;
        if(current_r<=0){
            minimum_r += 0 - current_r +1;
            current_r = 1;
        }
        
        int current_d = current + dungeon[row+1][col];
        int minimum_d = minimum;
        if(current_d<=0){
            minimum_d +=  0 - current_d +1;
            current_d = 1;
        }
        if(minimum_r>minimum_d){
            return travel(row+1,col,dungeon,rows,cols,minimum,current);
        }
        else if(minimum_r<minimum_d){
            return travel(row,col+1,dungeon,rows,cols,minimum,current);
        }
        else{
            return min(travel(row+1,col,dungeon,rows,cols,minimum,current),travel(row,col+1,dungeon,rows,cols,minimum,current));
        }
    }
}

int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int minimum = 1;
    int current = minimum;
    int rows = (int)dungeon.size();
    if(rows == 0)
        return 1;
    
    int cols = (int)dungeon[0].size();
    if(rows == 1){
        for (int i = 0; i<cols; i++) {
            current += dungeon[0][i];
            if(current<=0){
                minimum += 0 - current +1;
                current = 1;
            }
        }
        return minimum;
    }
    return travel(0,0,dungeon,rows,cols,minimum,current);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> >  map;
    vector<int> temp;
    
    temp.push_back(-2);
    temp.push_back(-3);
    temp.push_back(3);
    map.push_back(temp);
    temp.clear();
    
    temp.push_back(-5);
    temp.push_back(-10);
    temp.push_back(1);
    map.push_back(temp);
    temp.clear();
    
    temp.push_back(10);
    temp.push_back(30);
    temp.push_back(-5);
    map.push_back(temp);
    temp.clear();
    
    std::cout << calculateMinimumHP(map);
    return 0;
}
