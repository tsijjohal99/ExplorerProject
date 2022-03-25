#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <time.h>
#include <conio.h>

void printGrid(int &column,int &row, std::vector<std::vector<int>> grid) {
    std::cout << std::endl;
    for(int i = 0; i <= 2*row; i++) {
        for(int j = 0; j <= 2*column; j++){
            if(i%2==0) {
                if(j%2==0)
                    std::cout << " ";
                else std::cout<<"---";
            } else {
                if(j%2==0)
                    std::cout<<"|";
                else {
                    switch (grid[(i-1)/2][(j-1)/2]) {
                        case 1: {
                            std::cout<<" F ";
                            break;
                        } case 2: {
                            std::cout<<" G ";
                            break;
                        } case 3: {
                            std::cout<<" S ";
                            break;
                        } case 4: {
                            std::cout << " T ";
                            break;
                        } case 5: {
                            std::cout << " P ";
                            break;
                        }  case 6: {
                            std::cout << " E ";
                            break;
                        } default:{
                            std::cout<<"   ";
                        }   
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}

std::vector<int> updatePlayerPosition(int &row, int &column, char move, std::vector<std::vector<int>> &grid, std::vector<int> &treasure) {
    int playerPositionRow, playerPositionColumn;
    std::vector< std::vector<int> >::const_iterator rowIt;
    std::vector<int>::const_iterator colIt;
    for (rowIt = grid.begin(); rowIt != grid.end(); rowIt++) {
        colIt = find(rowIt->begin(), rowIt->end(), 1);
        if (colIt != rowIt->end() ) {
            playerPositionRow = rowIt - grid.begin();
            playerPositionColumn = colIt - rowIt->begin();
        }
    }
    grid[playerPositionRow][playerPositionColumn] = 0;
    switch (move) {
        case 'W':
        case 'w':{
            if (playerPositionRow == 1){
                row++;
                std::vector<int> add(column,0);
                grid.insert(grid.begin(),add);
                treasure[0]++;
            } else if (playerPositionRow > 1) {
                playerPositionRow--;
            }
            break;
        }
        case 'S':
        case 's':{
            playerPositionRow++;
            if (playerPositionRow == row - 1) {
                row++;
                std::vector<int> add(column,0);
                grid.push_back(add);
            }
            break;
        }
        case 'A':
        case 'a':{
            if (playerPositionColumn == 1) {
                column++;
                for (int i = 0; i < row; i++) {
                    grid[i].insert(grid[i].begin(),0);
                }
                treasure[1]++;
            } else if (playerPositionColumn > 1) {
                playerPositionColumn--;
            }
            break;
        }
        case 'D':
        case 'd':{
            playerPositionColumn++;
            if (playerPositionColumn == column - 1) {
                column++;
                for (int i = 0; i < row; i++) {
                    grid[i].push_back(0);
                }
            }
            break;
        }
        default: {
            std::cout << "Try again" << std::endl;
        }
    }
    grid[playerPositionRow][playerPositionColumn] = 1;
    return std::vector<int> {playerPositionRow,playerPositionColumn};
}

std::vector<int> generateTreasure(int mid) {
    std::vector<int> treasure{(rand() % 16) - 8 + mid, (rand() % 16) - 8 + mid};
    return treasure;
}

bool treasureDistance(std::vector<int> treasure, std::vector<int> playerPosition) {
    float distance = sqrt(pow(treasure[0] - playerPosition[0], 2) + pow(treasure[1] - playerPosition[1], 2));
    if (distance == 0) {
        return false;
    } else {
        std::cout << "You are " << distance << " blocks away from your objective." << std::endl;
        return true;
    }
}

void sceneOne() {
    std::cout << "Frodo: You're late!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: A wizard is never late, Frodo Baggins. Nor is he early. He arrives precisely when he means to." <<std::endl;
    Sleep(1000);
    std::cout << "Frodo: It's wonderful to see you Gandalf!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: <laughs> Ooh! You didn't think I'd miss your Uncle Bilbo's birthday?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: What news of the outside world? Tell me everything." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Everything? Far too eager and curious for a hobbit, most unnatural. Well what can I tell you? Life in the wide world goes on much as it has this past age, full of its own comings and goings. Scarcely aware of the existence of hobbits... which I am very thankful." << std::endl;
    Sleep(1000);
    std::cout << "Hobbit folk: Look it's Gandalf! Its Gandalf!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Ooh! The long expected party!" << std::endl;
    Sleep(1000);
    std::cout << "   So how is the old rascal? I hear it's got to be a party of special magnificence." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: You know Bilbo, he's got the whole place in an uproar." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Hmm, well now that should please him, hmmm." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Half the Shire's been invited." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Good gracious me" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: He is up to something." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Oh really..." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: All right then keep your secrets. <Gandalf laughs> Before you came along we Bagginses were very well thought of." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Indeed?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Never had any adventures or did anything unexpected." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: If you're referring to the incident with the dragon, I was barely involved. All I did was give your uncle a little nudge out of the door." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Whatever you did, you've been officially labeled a disturber of the peace." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Oh really?" << std::endl;
    Sleep(1000);
    std::cout << "Hobbit children: Gandalf! Gandalf! Fireworks? Gandalf?" << std::endl;
    Sleep(1000);
    std::cout << "<Gandalf pretends to ignore the children>" << std::endl;
    Sleep(1000);
    std::cout << "<fireworks suddenly go off from the cart> <hobbit children cheer>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Gandalf, I'm glad you're back." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: So am I, dear boy! So am I." << std::endl;
}

void sceneTwo() {
    std::cout << "Frodo: <sits beside Sam> Go on Sam! Ask Rosie for a dance." << std::endl;
    Sleep(1000);
    std::cout << "Sam: I think I'll just have another ale." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Oh no you don't. Go on. <pushes Sam to the dance floor and into Rosie’s arms. Frodo laughs aloud>" << std::endl;
    Sleep(1000);
    std::cout << "<Some stuff happens and Bilbo disappears.>" << std::endl;
  
}

void sceneThree() {
    std::cout << "Frodo: Bilbo! Bilbo!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: <mumbles> My precious. Precious..." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: He's gone hasn't he? He talked for so long about leaving. I didn't think he'd really do it. Gandalf?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Hmm. <smiles at Frodo> Bilbo's Ring. He's gone to stay with the elves. He's left you Bag End... <holds envelope open, Frodo slips in the Ring, Gandalf seals the envelope> ...along with all his possessions. The Ring is yours now. Put it somewhere out of sight." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Where are you going?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: There are some things that I must see to." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: What things?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Questions. Questions that need answering!" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: But you've only just arrived! I don't understand." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: <looks back at Frodo> Neither do I. Keep it secret. Keep it safe. <leaves>" << std::endl;
    Sleep(1000);
    std::cout << "<After a long time, Frodo returns to his house to discover Gandalf has broken in>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: <startled> Huh?!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Is it secret?! Is it safe?!" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Ah! <hands Gandalf the envelope>" << std::endl;
    Sleep(1000);
    std::cout << "<Gandalf throws the envelope to the fire>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: <alarmed> What are you doing?" << std::endl;
    Sleep(1000);
    std::cout << "<Gandalf gets a pair of tongs and picks up the Ring>" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Hold out your hand Frodo, it's quite cool. <drops the Ring on Frodo's hand> What can you see? Can you see anything?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Nothing. There's nothing... wait. There are markings. It's some form of elvish. I can't read it." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: There are few who can. The language is that of Mordor, which I will not utter here." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Mordor?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: In the common tongue it says, \"One Ring to rule them all, One Ring to find them. One Ring to bring them all and in the darkness bind them.\" This is the One Ring. Forged by the Dark Lord Sauron in the fires of Mount Doom. Taken by Isildur from the hand of Sauron himself." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Bilbo found it. In Gollum's cave." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Yes. For sixty years the Ring lay quiet in Bilbo's keeping, prolonging his life, delaying old age. But no longer Frodo. Evil is stirring in Mordor. The Ring has awoken. It's heard its master's call." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: But he was destroyed. Sauron was destroyed." << std::endl;
    Sleep(1000);
    std::cout << "Ring: <whispers> Isildur..." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: No, Frodo. The spirit of Sauron endured. His life force is bound to the Ring and the Ring survived. Sauron has returned. His orcs have multiplied. His fortress of Barad-Dur is rebuilt in the land of Mordor. Sauron needs only this Ring to cover all the lands of a second darkness. He is seeking it. Seeking it, all his thought is bent on it. The Ring yearns above all else to return to the hand of its master. They are one, the Ring and the Dark Lord. Frodo, he must never find it." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Alright, we put it away. We keep it hidden. We never speak of it again. No one knows it's here, do they? Do they Gandalf?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: There is one other who knew that Bilbo had the Ring. I looked everywhere for the creature Gollum. But the enemy found him first. I don't know how long they tortured him. Amidst the std::endless screams and inane babble, they discerned two words:" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Take it Gandalf! Take it!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: No Frodo no." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: You must take it!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: You cannot offer me this Ring!" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: I'm giving it to you!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Don't tempt me Frodo! I dare not take it. Not even to keep it safe. Understand Frodo, I would use this Ring from the desire to do good. But through me, it would wield a power to great and terrible to imagine." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: But it cannot stay in the Shire!" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: No! No it can't." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: What must I do?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: You must leave and leave quickly." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Where? Where do I go?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Get out of the Shire. Make for the village Bree." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Bree. What about you?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: I'll be waiting for you, at the Inn of the Pranstd::cing Pony." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: And the Ring will be safe there?" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: I don't know Frodo. I don't have any answers. I must see the head of my order. He is both wise and powerful. Trust me Frodo, he'll know what to do. You'll have to leave the name of Baggins behind you, for that name is not safe outside the Shire. Travel only by day. And stay off the road." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: I can cut across country easily enough." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: My dear Frodo. Hobbits really are amazing creatures! You can learn all that there is to know about their ways in a month, and yet after a hundred years, they can still surprise you. <hears rustling of the leaves> Get down!" << std::endl;
    Sleep(1000);
    std::cout << "<Frodo drops to the floor. Gandalf goes to the window, peers out cautiously then gives the bushes a whack with his staff>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: Oooff!! <Gandalf drags Sam up by his hair and plops him onto the table>" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Confound it all Samwise Gamgee! Have you been eavesdropping?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: I have been droppin' no eves sir, honest. I was just cutting the grass under the window there, if you follow me." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: A little late for trimming the verge don't you think?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: I heard raised voices." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: What did you hear?! Speak!!!!" << std::endl;
    Sleep(1000);
    std::cout << "Sam: N-n-n-nothing important. That is I heard a good deal about a Ring and a Dark Lord and something about the end of the world but... Please, Mister Gandalf sir, don't hurt me. Don't turn me into anythin' --unnatural." << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: No, perhaps not. I have thought of a better use for you…" << std::endl;
    Sleep(1000);
    std::cout << "<Cuts to the scene outside the following morning>" << std::endl;
    Sleep(1000);
    std::cout << "Gandalf: Come along Samwise, keep up! Be careful both of you. The enemy has many spies in his service: birds, beasts. <turns to Frodo> Is it safe? <Frodo pats his vest pocket> Never put it on, for the agents of the Dark Lord will be drawn to its power. Always remember, Frodo, the Ring is trying to get back to its master. It wants to be found." << std::endl;
}

void sceneFour() {
    Sleep(1000);
    std::cout << "Sam: This is it." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: <turns> This is what?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: I take one more step, it'll be the farthest away from home I've ever been." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: <reassuringly> Come on Sam. Remember what Bilbo used to say: \"It's a dangerous business... <segues to Bilbo's voice> ...Frodo, going out your door. You step onto the road, and if you don't keep your feet, there's no knowing where you might be swept off to.\"" << std::endl;
}

void sceneFive() {
    Sleep(1000);
    std::cout << "Sam: <starts to panic> Mister Frodo? Frodo! Frodo!" << std::endl;
    Sleep(1000);
    std::cout << "<Frodo emerges from the bend in the path, looking puzzled>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: <sigh> I thought I'd lost you." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: What are you talking about?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: It's just something Gandalf said." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: What did he say?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: \"Don't you lose him Samwise Gamgee!\" And I don't mean to." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: < amused > Sam, we're still in the Shire. What could possibly happen?" << std::endl;
    Sleep(1000);
    std::cout << "<Suddenly, Pippin bursts from the cornfield and knocks over Frodo. Merry, close behind, barrels out, knocking over Sam. Both have an armful of vegetables>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Frodo? Merry! It's Frodo Baggins." << std::endl;
    Sleep(1000);
    std::cout << "Merry: Hello Frodo!" << std::endl;
    Sleep(1000);
    std::cout << "Sam: Get off him! <hauls Pippin off Frodo> Frodo? Are you all right?" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: What's the meaning of this?" << std::endl;
    Sleep(1000);
    std::cout << "Merry: Hold this. <hands vegetables to Sam>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: You've been into Farmer Maggot's crop!" << std::endl;
    Sleep(1000);
    std::cout << "<They hear a dog barking and an angry, yelling voice. Pippin grabs Frodo and runs, followed by Merry. Sam does a double take on the produce in his hands, drops them and runs after the others>" << std::endl;
    Sleep(1000);
    std::cout << "Farmer Maggot: <brandishing a scythe> Wait till I get this through you! Stay out of my fields! You ruffians I'll catch up with you!" << std::endl;
    Sleep(1000);
    std::cout << "Merry: 'Dunno why he is so upset. It's only a couple of carrots!" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: And some cabbages. And those few bags of potatoes that we lifted last week and, and the mushrooms the week before!" << std::endl;
    Sleep(1000);
    std::cout << "Merry: Yes Pippin! My point is, he is clearly overreactin'. Run!" << std::endl;
    Sleep(1000);
    std::cout << "<Pippin, Frodo and Merry stops just before the edge of the hill. Sam slams into them from behind and all four hobbits roll down the hill>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Ooh! That was close" << std::endl;
    Sleep(1000);
    std::cout << "Merry: Ow! I think I've broken something. <pulls out a broken carrot>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: Trust a Brandybuck and a Took!" << std::endl;
    Sleep(1000);
    std::cout << "Merry: What?! That was just a detour, a shortcut." << std::endl;
    Sleep(1000);
    std::cout << "Sam: A shortcut to what?" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Mushrooms!!!" << std::endl;
    Sleep(1000);
    std::cout << "<Sam and Merry rush towards the mushrooms, followed by Pippin. Frodo, standing, looks down the road>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: That's mine!" << std::endl;
    Sleep(1000);
    std::cout << "Hobbits: Mmm..." << std::endl;
    Sleep(1000);
    std::cout << "Merry: Here is a nice one Sam." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: I think we should get off the road." << std::endl;
    Sleep(1000);
    std::cout << "<Sounds of the Nazgul can be heard, coming up the road>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Get off the road! Quick!" << std::endl;
}

void sceneSix() {
    Sleep(1000);
    std::cout << "Merry: What was that?" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Anything?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Nothing." << std::endl;
    Sleep(1000);
    std::cout << "Pippin: What is going on?" << std::endl;
    Sleep(1000);
    std::cout << "Merry: That Black Rider was looking for something… or someone. Frodo?" << std::endl;
    Sleep(1000);
    std::cout << "Sam: Get down!" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: I have to leave the Shire. Sam and I must get to Bree." << std::endl;
    Sleep(1000);
    std::cout << "Merry: Right. Buckleberry Ferry. Follow me." << std::endl;
}

void sceneSeven() {
    Sleep(1000);
    std::cout << "Gatekeeper: What do you want?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: We're heading for the Pranstd::cing Pony." << std::endl;
    Sleep(1000);
    std::cout << "Gatekeeper: Hobbits! Four hobbits! What business brings you to Bree?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: We wish to stay at the inn. Our business is our own." << std::endl;
    Sleep(1000);
    std::cout << "Gatekeeper: Alright young sir, I meant no offence. 'Tis my job to ask question after nightfall. There's talk of strange folk abroad. Can't be too careful." << std::endl;
    Sleep(1000);
    std::cout << "<Hobbits come up the cobble stone path, working their way through the crowd>" << std::endl;
    Sleep(1000);
    std::cout << "Men of Bree: Move! Watch where you're going!" << std::endl;
    Sleep(1000);
    std::cout << "<Hobbits enter the Pranstd::cing Pony>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Excuse me?" << std::endl;
    Sleep(1000);
    std::cout << "Butterbur: Good evening little masters! If you're seeking accommodation we've got some nice, cozy, hobbit-sized rooms available. Mr. uh--" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: --Underhill, my name's Underhill." << std::endl;
    Sleep(1000);
    std::cout << "Butterbur: Underhill. Hmm." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: We're friends of Gandalf the Grey. Can you tell him we've arrived?" << std::endl;
    Sleep(1000);
    std::cout << "Butterbur: Gandalf? Gandalf? Ohhh yes! I remember, elderly chap, big gray beard, pointy hat. Not seen him for 6 months." << std::endl;
    Sleep(1000);
    std::cout << "<The hobbits are shocked. Worry crosses their faces>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: What do we do now?" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Sam. He'll be here. He'll come." << std::endl;
    Sleep(1000);
    std::cout << "Man: <to Merry coming from the bar> Get, get out of my way." << std::endl;
    Sleep(1000);
    std::cout << "<Merry sits down at the table. He is holding a huge stein of beer, which he sets down reverently>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: What's that?" << std::endl;
    Sleep(1000);
    std::cout << "Merry: This my friend, is a pint." << std::endl;
    Sleep(1000);
    std::cout << "Pippin: It comes in pints? I'm getting one. <rushes to the bar>" << std::endl;
    Sleep(1000);
    std::cout << "Sam: You had a whole half already!" << std::endl;
    Sleep(1000);
    std::cout << "<Sam turns back to his mug. After a moment, he nudges Frodo>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: <takes Barliman aside> Excuse me, that man in the corner, who is he?" << std::endl;
    Sleep(1000);
    std::cout << "Butterbur: He's one of them rangers. Dangerous folk they are-- all wandering the wilds. What his right name is I've never heard but around here, he's known as Strider." << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Strider..." << std::endl;
    Sleep(1000);
    std::cout << "<Frodo starts to play with the Ring. It starts to whisper, tempting him to use it>" << std::endl;
    Sleep(1000);
    std::cout << "The Ring: Baggins. Baggins. Baggins. Baggins! Baggins!..." << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Baggins!" << std::endl;
    Sleep(1000);
    std::cout << "<Frodo snaps out of his reverie>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: <at the bar> Sure I know a Baggins. He's over there, Frodo Baggins. He's my second cousin once removed on his mother's side <listeners laugh, \"It works for him!\" yells one> and my third cousin twice removed on his father's side, if you follow me." << std::endl;
    Sleep(1000);
    std::cout << "<Frodo rushes towards the bar to stop Pippin from babbling further>" << std::endl;
    Sleep(1000);
    std::cout << "Frodo: Pippin! <grabs him>" << std::endl;
    Sleep(1000);
    std::cout << "Pippin: Steady on!" << std::endl;
    Sleep(1000);
    std::cout << "<Frodo slips on someone's boot and falls back, tossing the Ring into the air. As he catches it, the Ring slips onto Frodo's finger. He disappears. Bree folks gasp in surprise. The Nazgul are alerted and makes for Bree. Frodo, now in the Shadow World, looks around mystified. He then sees an immense singular orb, a lidless eye, wreathed in flame. The Eye of Sauron stares down at him>" << std::endl;
}

int main() {
    system("cls");
    srand((unsigned) time(0));

    int scenes = 8;
    int scene = 0;

    do {
        int size = 3;
        int mid = (size - 1)/2;
        int column = size;
        int row = size;
        bool gameRunning = true;
        std::vector<std::vector<int>> grid(row, std::vector<int>(column,0));
        std::vector<int> treasure = generateTreasure(mid);
        switch (scene) {
            case 5: {
                std::cout << "Quick, find a hiding place" << std::endl;
            } 
            case 0:
            case 1:
            case 2: 
            case 6:
            case 7: 
            case 3: 
            case 4:{
                grid[mid][mid] = 1;
                break;
            }
        }
        
        while (gameRunning) {
            if (treasure[0] < row && treasure[1] < column) {
                switch (scene) {
                    case 0: 
                    case 2: {
                        grid[treasure[0]][treasure[1]] = 2;
                        break;
                    }
                    case 1: 
                    case 3:
                    case 4:{
                        grid[treasure[0]][treasure[1]] = 3;
                        break;
                    }
                    case 5: {
                        grid[treasure[0]][treasure[1]] = 4;
                        break;
                    }
                    case 6: {
                        grid[treasure[0]][treasure[1]] = 5;
                        break;
                    }
                    case 7: {
                        std::cout << "Escape" << std::endl;
                        grid[treasure[0]][treasure[1]] = 6;
                        break;
                    }
                } 
            }
            printGrid(column, row, grid);   
            char move;
            std::cout << "Enter a move (wasd or 0 to exit): " << std::endl;
            move = getch();
            if (move == '0') {
                gameRunning = false;
            } else {
                std::vector<int> playerPosition = updatePlayerPosition(row, column, move, grid, treasure);
                system("cls");
                gameRunning = treasureDistance(treasure, playerPosition);
            }
        }
        printGrid(column, row, grid);
        switch(scene){
            case 0: {
                sceneOne();
                break;
            } 
            case 1: {
                sceneTwo();
                break;
            } 
            case 2: {
                sceneThree();
                break;
            } 
            case 3: {
                sceneFour();
                break;
            } 
            case 4: {
                sceneFive();
                break;
            } case 5: {
                sceneSix();
                break;
            } case 6: {
                sceneSeven();
                break;
            }
        }
        scene++;
    } 
    while (scene < scenes);
    return 0;
}