/*
MIT License

Copyright (c) 2021 JenmirGH

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;






int main() {
    string line_entry;
    string type;
    string filename_in = "list.txt";
    const char list[] = "dir /b > list.txt";

    system(list);

    cout << "# IMPORTANT, create the data folders in the proper locations before running this program." << endl;
    cout << "# Enter which type of asset is being read (tilesets for simple tilesets, smart tilesets aren't supported yet):" << endl;

    cin >> type;

    ifstream inp(filename_in);
    
    if (!inp)			
	{
		cout << "# Didn't find any files, terminating program." << filename_in << endl;
		return 0;
	}

    if (type == "objects")
    {
        string filename_out = "labels.txt";
        ofstream out(filename_out);
        while(!inp.eof())
        {
            inp >> line_entry;
            if (line_entry != "list.txt" && line_entry != "labels.txt" && line_entry != "dungeondraft_data_maker.exe")
            {
                out << "\"textures/" << type << "/" << line_entry << "\"," << endl;
                cout << "# read: " << line_entry << endl;
            }    
        }
    }

    else if (type == "walls")
    {
        while(!inp.eof()){
            inp >> line_entry;
            string line_entry_name = line_entry;
            line_entry_name.erase(line_entry.length()-4);
            string wall_out = "../../data/walls/" + line_entry_name + ".dungeondraft_wall";
            if (line_entry != "list.txt" && line_entry != "labels.txt" && line_entry != "dungeondraft_data_maker.exe" && line_entry.find("_end") == string::npos)
            {
                ofstream w_out(wall_out);
                w_out   << "{" << endl 
                        << "\"path\": \"textures/walls/" << line_entry << "\"," << endl 
                        << "\"color\": \"ffffff\"" << endl 
                        << "}";
                cout << "# read: " << line_entry << endl;
            }    
        }
    }

    else if (type == "tilesets")
    {
        string color_type;
        cout << "# Color type: normal or custom_color? (Custom will only color reddish parts)" << endl;
        cin >> color_type;
            if (color_type == "normal" || color_type == "custom_color"){}

            else
            {
                cout << "# Invalid color type, terminating program." << endl;
                return 0;
            }
            
            
        while(!inp.eof())
        {
            inp >> line_entry;
            string line_entry_name = line_entry;
            line_entry_name.erase(line_entry.length()-4);
            string tile_out = "../../../data/tilesets/" + line_entry_name + ".dungeondraft_tileset";
            if (line_entry != "list.txt" && line_entry != "labels.txt" && line_entry != "dungeondraft_data_maker.exe")
            {
                ofstream t_out(tile_out);
                t_out   << "{" << endl 
                        << "\"path\": \"textures/tilesets/simple/" << line_entry << "\"," << endl
                        << "\"name\": \"" << line_entry_name << "\"," << endl
                        << "\"type\": \"" << color_type << "\"," << endl 
                        << "\"color\": \"ffffff\"" << endl 
                        << "}";
                cout << "# read: " << line_entry << endl;
            }    
        }
    }
    
    
    
    system("pause");
    return 1;
    }

    