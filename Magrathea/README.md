# Magrathea

Jeu 2d —> Comme Terraria

## Liens documentation

[Bruit de Perlin](https://fr.wikipedia.org/wiki/Bruit_de_Perlin)

[Fast inverse square root](https://en.wikipedia.org/wiki/Fast_inverse_square_root)

## Open Project :

- Rendre le jeux plus clean (passer en POO ?)
- Rendre le jeux cross-os (donc gerer les bails de MinilibX voir la faire sauter), faire en sorte que ca soit stable, …
- Rajouter des fonctionnalites
- 

## Ambiance :

- Differents biomes, mais un truc semi fantastique, avec du steampunk → Villes dans le style victorien, grottes un peu mines
    - Forets : 4/5 biomes de forets differentes, avec des efles associes a chaque forets, les structures generees suivent la meme trame mais dans des ambiances un peu differentes, avec des mecaniques qui changent
    **Structure de la foret :**
    - Ville elfe → Ville dans les arbres, avec des chemins entre les arbres, des arbres plus imposants, …
    - Donjon forestier → Structure un peu typee pyramide maya → Des pieges differents en fonction de la foret mais quelques etages avec du stuff reparti un peu partout
    **Specificite elfes :**
    - Bons chasseurs, cuisiniers : Possibilite d’apprendre des plans pour construire des pieges pour les animaux, et a mieux cuisiner → Meilleures recuperation des stats
    - Possibilite de choper une benediction sur la regen d’une stat, ou de choper des amulette de bouffe, … 
    *Amelioration en general d’une stat ou 2*
    - Montagne : 3 biomes de montagne, avec des nains, des mines, des pourcentage d’apparition de minerais differents (en fonction de la montagne ca peut etre du cuivre, du fer ou de l’or)
    **Structure de la montagne :**
    - Galeries naines → Reseau de galeries qui amene a une grande cite naine, avec des ponts, des salles pour festoyer, …
    - Salles des coffres piegees → pas mal de pieges pour recuperer quelques ressources chiantes a obtenir sans ca
    **Specificite naines :**
    - Bons forgerons, et possibilite de voler des bons materiaux mais pas trop broken
    - Ateliers d’amelioration → Possibilite d’ameliorer son equipement en montant sa maitrise dans le metier, en faisant plus ou moins d’amelioration, avec les bons materiaux et tt.
    *Amelioration de l’equipement*
    - Villes : 4 tailles de villes differentes : **Race** : humains → Centres sur la magie, donc possibilite d’apprendre des sorts surtout, mais ils sont plutot bons dans tous
    - **Megalopole** → Super grande ville, tres verticale, avec beaucoup d’interactions possibles et pas mal de loot, des blocs plus rares aussi (teleporteurs, …) → Si le joueur arrive a entrer dans une salle des coffres, il a une possibilite de trouver une tres bonne piece d’equipement ou un tres bon materiaux de renforcement mais ne peut prendre qu’une chose sauf si talent voleur, il se fait teleporter dans un endroit aleatoire juste apres
    - **Capitale** → Generation potentielle d’une grande structure (tour de mage, grande bibliotheque, …) avec des possibilites d’apprendre de nouvelles competences plutot rares
    - **Ville** → Pas grand chose d’interessant, souvent du stuff de base, des materiaux corrects qui permettent d’avancer dans l’aventure
    - Hameau → Quelques batisses, rien de bien interessant
    - Plaines : Du vide, on peut trouver quelques structures dedans, ou des zones un peu speciales, des mobs type cheval et tt
    → Especes presentes : Furys (les hommes animaux) → Bons en survie et peuvent enseigner les bases de la survie
    - Ocean : Sirenes, tritons, poisson ; possibilite d’apparition de donjon de l’eau ou de cite sous marine mais difficulte due au cote aquatique
    - Developpement de sous-marin dans les cites cotieres ?
    → Especes presentes : Sirenes, tritons, … → Permettent d’apprendre des competences de negociation, et de manipulation mentale
    - Falaises : Milieu tres verticale,  avec des aigles, et des creatures volantes qui peuvent etre apprivoisees
    → Especes presente : Barbares (Des humanoides plutot grands avec de bonnes stats de combat) → Apprennent le combat en general, les strategies a connaitre
    - Possibilite de chopper des bonnes montures qui volent → Meilleure vitesse de deplacement
    
    # To Do :
    
    **I . Dev libraires**
    Ajouter ca a la libft
    
    - Random.h
        - Developper un moyen de creer du random en C
        → Generer du vrai et du faux random
        → regarder dans le dev/random
        - Trouver un moyen de crypter les datas en C ?
    - Math.h
        - Fonctions de calcul de base pour generer les maps
    
    **II . Generation procedurale de map**
    
    → Regarder le bruit de perlin (pour la generation de la map)
    
    - Probabilites que chaque partie de la map apparaissent, puis qu’elle soient cote a cote
    - Generation des structures qui suivent certaines regles de probabilites
    - Transitions smooths entre les biomes, faire des enchainements de biomes coherents (ne pas mettre un desert a cote d’une montagne eneigee par exemple)
    - 
    
    **III . Rajouter les fonctionalites suivantes :**
    
    - Gravite → Si rien sous les pieds ET pas de talents/effets allant contre la gravite, le joueur doit tomber, avec une acceleration continue, et des degats proportionnels a la vitesse ou il touche le sol (plus simple a dev I guess), en fonction de la matiere du sol les degats peuvent etre reduits
    - Stats du joueur → Faire une grosse page de stats et de sous stats non-connues
        - Force 
        → Decoule sur la capacite a gerer sa force, ainsi que l’amplitude de cette derniere (pouvoir soulever des charges tres lourdes, mais savoir tapoter tout doucement)
        - Dexterite 
        → Decoule sur la capacite a bien utiliser son corps et maitriser tous ses nouvements
        - Constitution 
        → Decoule directement sur les capacites de survie, les PV mais aussi les reflexes du corps en combat et la maitrise des techniques de combat au corps a corps
        → Possibilite de se specialiser dans certaines defense (contre les degats physique, contre les degats magique, contre les degats du mal, contre les degats du bien), …
        - Inteligence 
        → Decoule sur les connaissances (sorts, techniques, …)
        - Sagesse 
        → Decoule sur la capacite a reflechir (peut debloquer une plus grande vitesse d’invocation des sorts, la possibilite d’enchainer plusieurs coups avec des legers deplacements)
        - Charisme 
        → Decoule sur l’image renvoyee aux autres, et peut permettre de debloquer des quetes cachees, se jouer des autres, …
        
        - Points de Mana 
        → Augmentent avec la sagesse et l’intelligence (plus le niveau du personnage)
        → Permettent de lancer les sorts. Ces derniers ont des coups en mana qui peuvent changer en fonction de la maitrise de ces derniers
        → Possibilite de les faire monter grace a des amulettes, des bagues, …
        - Points de vie 
        → Permettent de prendre beaucoup de coups, en fonction de la constitution et des talents, leur regeneration peut etre plus ou moins rapide
        - Alignement
        → Choisir le bien → Permet d’avoir des buffs de soin, a un certain niveau d’invoquer des armes celestes benites, de voler avec des ailes d’ange, …
        → Choisir le mal → Permet d’avoir des buffs de vol de vie, de necromancie, …
    - Systemes de coups
        - Coup simple
        → Coute peu de stamina sauf pour les classes qui n’ont pas l’habitude de se battre physiquement (genre MAGE bande de fdp)
        → Le joueur fait un clic gauche et ca tappe avec son arme principale
        → L’utilisation de la roulette permet de changer parmis les armes chargees et pretes a l’utilisation → Les armes ont toutes les stats de range, degats, type de degats, …
        - Coups speciaux
        → Coute de la stamina en fonction de la maitrise du coup, de la constitution et de la dexterite
        → Coups debloques par l’entrainement, monter de niveau dans une classe precise
        → Activation via une roue speciale, qui permet en restant appuye sur cette touche et avec un glisse souris de selectionner le coup a faire (leger cooldown)
    - Nouveaux mouvements 
    → synchronises (deplacements horizontaux durant la chute ou les sauts)
    → Mouvements speciaux : Animations des differentes attaques/combots, double sauts, nage, …
    → Acces a une roue de deplacements pour les deplacements speciaux qui dependent de competences (similaire aux coups speciaux)
    - Creation des nouveaux assets, des ambiances et des variations de map (tempete de sable, neige, pluie, grand soleil, …)
    - Ajout du systeme de craft et d’inventaire
    - Ajout des mobs ennemis et allies, du systeme de reputation qui peut changer leur attitude
    - Dev les animations et le jeu smooth et agreable a jouer
    - Rajouter le systeme de zoom (molette ou  touches “+” & “-”) → Le zoom doit faire transitioner entre des textures 16*16, 32*32, 64*64 (donc zoom x2 a chaque clic)
    
    **IV . Developper les nouveaux assets :**
    
    - Nouveaux blocs, avec les noms associes (faire des noms simples et/ou comprehensibles)
    - Gerer les niveaux de luminosite avec des masques pre-faits pour faire +- sombre
    - Gerer des masques pre-faits en cas d’utilisation de talents (ralentissement du temps, invocation de la lumiere, invocation du mal, …)
    - Generer les ambiances sonores de chaque lieu, les sons associes aux differentes actions
    
    ---
    
    # Attentes en fin de jeu:
    
    **I . Specs du jeu :**
    
    - 30 fps → Animation fluides, deplacements fluides, generation des maps fluides
    GENERATION DES MAPS → decouper la grande map en fonction de l’ecran (pour garder charge en permanence 9 ecran (celui affiche, et tout autour) + permettre de decharger quand on passe de coupure en coupure
    - Generation rapide des maps
    - Ecran d’accueil
        - Creer un nouveau monde → Generation d’une map et en fond : Creation d’un nouveau folder, on range la map dedans et on change le $(GAME_PATH) a ce folder
        - Choisir une ancienne save → On choisis la game qu’on veut reprendre (on leur donne un nom a toutes pour choisir plus facilement)
        - Changer les settings
    -