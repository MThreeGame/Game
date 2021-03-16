#include "Terrain.h"


// Let's read the file to create the equivalent matrix
struct Pixel
{
    int R;
    int G;
    int B;
};


vector<vector<Cell>> readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
vector<vector<Cell>> readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << "width : " <<  width << endl;
    cout << "height" << height << endl;
    

    // allocate 3 bytes per pixel
    int size = 3 * width * height;

    unsigned char* data = new unsigned char[size];

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f); 
    fclose(f);



    for(i = 0; i < size; i += 3)
    {
            // flip the order of every 3 bytes
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }

    cout << data[0];
    //return data;
    return NULL;
}


    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << "width : " <<  width << endl;
    cout << "height" << height << endl;
    

    // allocate 3 bytes per pixel
    int size = 3 * width * height;

    unsigned char* data = new unsigned char[size];

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f); 
    fclose(f);



    for(i = 0; i < size; i += 3)
    {
            // flip the order of every 3 bytes
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }

    cout << data[0];
    //return data;
    return NULL;
}








Terrain::Terrain(){
    // let's initialise one rectangle 
    //Set the wall
    SDL_Rect wall;
    wall.x = 30;
    wall.y = 40;
    wall.w = 40;
    wall.h = 20;

    grounds.push_back(wall);
}


vector<SDL_Rect> Terrain::getGrounds(){
    return grounds;
}


string Terrain::getPathToImage(){
    return pathToImage;
}
