# dungeondraft_data_maker
A small program for windows I put together to create the data files for walls or simple tilesets or a list of properly formated labels to put into the tag file because I couldn't find a program for the wall and tileset files. 

If you are looking for a more advanced tool to label your objects [EightBitz's /
Dungeondraft-Custom-Tags](https://github.com/EightBitz/Dungeondraft-Custom-Tags) does it all with a very nice GUI, however I couldn't find any better program to do the wall and tileset files so I made my own. 

When executed it reads all the filenames present in that folder and asks if objects, walls or tilesets are read.
  - "objects" will create a "labels.txt" file in the folder, which are formated to be copied over to the default.dungeondraft_tags file. 
  - "walls" will write a seperate .dungeondraft_wall file for each file in the folder, excluding the program, the "end" pieces of the wall and the .txt files it creates, the default color will always be "ffffff". 
  - "tilesets" will create seperate .dungeondraft_tileset files for each file in the folder, excluding itself and the .txt files it creates. It askes if the color type is "normal" or "custom_color" where "normal" will make Dungeondraft color the entire image while "custom_color" will only color the reddish parts of the image. Again the default color is set to ffffff.

# Suggested workflow
In order for this program to work, the filenames may not contain any spaces, no subfolders can be in the folder it's executed in (it reads them aswell) and the destination folders must be present. For the "walls" and "tilesets" to work, it must be executed inside the /textures/walls or textures/tilesets/simple folder respecively (it wont find the data folders otherwise).
 
  *walls*
  1. Place the wall.png(s), wall_end.png(s) and the program inside the /textures/walls folder. 
  2. Execute the program and enter "walls" (without the quotes).
  3. Done
  
  *tilesets*
  1. Place the tilesets in the textures/tilesets/simple folder (make sure they are tiled 4x4, 1024x1024 pixels and around 100ppi to have them properly scaled in Dungeondraft.)
  2. Copy the program into the same folder and execute it.
  3. Enter "tilesets" and then "normal" if you have black and white tilesets or "custom_color" if you have precolored tiles. (Again exclude the quotes)
  4. Done
 
  *Label objects*
  1. Sort your assets into seperate folder for each label you want to create
  2. Copy the compiled program into the folder with the assets and execute it.
  3. Enter "objects" when asked which type is being read (without the quotes).
  4. A file called "labels.txt" will be created in the folder alongside the "list.txt", which you don't need.
     Copy the contents of "labels.txt" into the default.dungeondraft_tags file inside the square brackets for your tag.
  4.1 If you have colorable assets, copy them to a seperate folder and run the program for "objects" in there again (no need to seperate by tag here) and copy the created labels to the "Colorable" tag.
  5. Remove the program and .txt files it created from the folder and move all objects from their seperate folders into the /textures/objects folder.
  6. Done
   
   Now you can package your custom assets pack.


# Known issues
Haven't yet figured out how to make a compiled release on github XD, so I just put it up as a file.
1. If a space is present in a filename, it isn't read in its entirety, making the created label or data file useless.
2. If the tilesets and walls folders aren't already present in the data folder, no files will be created.
3. Not too great feedback on what the programm does, it just exits when the type of asset to be read is spelled wrong.
4. Code does not yet contain any comments.
5. Subfolders are also read by the program, so it only works if no subfolders are present.
6. Only compatible with windows.
