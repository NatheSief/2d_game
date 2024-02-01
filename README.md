# SO-LONG

This project is a very small 2D game. </br>
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements. </br>

## MANDATORY-PART
- This Mandatory part is a way to learn how to use the graphic library ; how to use the different ways to free the structs allocated, ...

- There are some rules to follow in order to validate the project :
    <ol>
    - The map has to be a rectangle surrounding by walls, the all fittind in the monitor. </br>
    - You can only have one player in the map, one exit and at least one collectible </br>
    - It should be a valid path in the map for the player to collect all the collectibles before exiting the map with the exit </br>
    </ol>

- With all this, I created a first game, without anything for the bonuses (animation, ennemies, ...)

### Play the game - Linux player only:

1. Open your terminal

2. Git clone the project ```git clone https://github.com/NateSief/2d_game.git```

3. Go in the game folder ```cd 2d_game```

4. Compile the game ```make mandatory```

5. Execute the game with a map of you choice ```./so_long mandatory-part/maps/```

6. Play with W,A,S,D keys

## MAGRATHEA
While coding the Mandatory part, I realise I wanted to go way further than the little game I developped. I decided to create a full game, fun to play with way more liberty in the actions the player can do.
I decided to create a sand box, following the So-long rules (rectangle, walls, path, ...) but with big functionalities (Procedural generation, game stats, in game lore with PNG, ...). All this could be easy, but I decided to do it in C, following almost all the rules of 42 norm (5 functions in a file, functions of 25 lines maximum, 80 caracters per lines, ...), with the Minilibx.

I'm actually working on the project, while doing the 42 Common Core ; stay tunned I'm gonna make a banger (I wish for real). 

## CNOSSOS
