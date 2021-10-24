#include "library.h"
#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  struct song_node *a_artists;
  printf("Testing insert_node:\n");
  a_artists = construct_song("Highway to Hell","AC/DC");
  a_artists = insert_node(a_artists,construct_song("Thunderstruck","AC/DC"));
  a_artists = insert_node(a_artists,construct_song("Dirty Deeds Done Dirt Cheap","AC/DC"));
  a_artists = insert_node(a_artists,construct_song("Dude Looks Like a Lady","Aerosmith"));
	
  printf("\n=====================\n");
  printf("Testing print_list:\n");
  print_list(a_artists);
  
  printf("\n=====================\n");
  printf("Testing find_song:\n");
  printf("Should be Highway to Hell: ");print_song(find_song(a_artists,"Highway to Hell","AC/DC"));
  printf("Should be D4C: ");print_song(find_first_song(a_artists,"AC/DC"));
  printf("Random Song: ");print_song(random_song(a_artists));
  
  printf("\n=====================\n");
  printf("Testing remove_song:\n");
  printf("\nRemoving Song: %s","Dirty Deeds Done Dirt Cheap\n");
  a_artists = remove_song(a_artists,"dirty Deeds Done Dirt Cheap","AC/DC");
  print_list(a_artists);
  printf("Removing Song: %s","Thunderstruck\n");
  a_artists = remove_song(a_artists,"thunderstruck","AC/DC");
  print_list(a_artists);
  printf("Removing Song: %s","Highway to Hell\n");
  a_artists = remove_song(a_artists,"highway to Hell","AC/DC");
  print_list(a_artists);
  
  printf("\n=====================\n");
  printf("Adding elements back:\n");
  a_artists = insert_node(a_artists,construct_song("Highway to Hell","AC/DC"));
  a_artists = insert_node(a_artists,construct_song("Thunderstruck","AC/DC"));
  a_artists = insert_node(a_artists,construct_song("Dirty Deeds Done Dirt Cheap","AC/DC"));
  
  printf("\n=====================\n");
  printf("Testing find_artist:\n");
  printf("Should be Dude Looks Like a Lady\n");
  print_song(find_first_song(a_artists,"aerosmith"));
  
  printf("\n=====================\n");
  printf("Freeing list... \n");
  a_artists = free_list(a_artists);
  print_list(a_artists);

  printf("\n=====================\n");
  printf("Library Testing:\n");
  
  struct song_node **lib = create_library();
  struct song_node *temp;
  
  printf("\n=====================\n");
  printf("testing print_library:\n");
  print_library(lib);
  
  printf("\n=====================\n");
  printf("adding black sabbath\n");
  add_song(lib,construct_song("Black Sabbath","Black Sabbath"));
  printf("adding paranoid\n");
  add_song(lib,construct_song("Paranoid","Black Sabbath"));
  printf("adding hip to be square\n");
  add_song(lib,construct_song("It's Hip to Be Square","Huey Lewis & the News"));
  printf("adding highway to hell\n");
  add_song(lib,construct_song("Highway to Hell","AC/DC"));
  
  printf("\n=====================\n");
  printf("testing print_library:\n");
  print_library(lib);
  
  printf("\n=====================\n");
  printf("testing find_song:\n");
  
  printf("looking for \"black sabbath\",\"black sabbath\"\n");
  print_song(find_song_library(lib,"black sabbath","black sabbath"));
  printf("looking for \"huey lewis & the news\",\"it's hip to be square\"\n");
  print_song(find_song_library(lib,"it's hip to be square","huey lewis & the news"));
  printf("looking for \"obama\",\"for whom the bell tolls\"\n");
  print_song(find_song_library(lib,"for whom the bell tolls","obama"));
  
  printf("\n=====================\n");
  printf("testing find_artist_library & print_artist_songs:\n");
  printf("(print_artist_songs calls find_artist_library)\n");
  
  printf("looking for \"black sabbath\"\n");
  print_artist_songs(lib,"black sabbath");
  printf("looking for \"ronald reagan\"\n");
  print_artist_songs(lib,"ronald reagan");
  
  printf("\n=====================\n");
  printf("testing delete_song:\n");
  
  printf("removing 'black sabbath': 'paranoid'\n");
  delete_song(lib,find_song_library(lib,"Paranoid","Black Sabbath"));
  print_library(lib);
  printf("removing 'huey lewis & the news': 'it's hip to be square'\n");
  delete_song(lib,find_song_library(lib,"it's hip to be square","huey lewis & the news"));
  print_library(lib);
  printf("removing 'ac/dc': 'highway to hell'\n");
  delete_song(lib,find_song_library(lib,"highway to hell","ac/dc"));
  print_library(lib);
  printf("removing 'black sabbath': 'black sabbath'\n");
  delete_song(lib,find_song_library(lib,"black sabbath","Black Sabbath"));
  print_library(lib);
  
  printf("\n==========  readding songs  ===========\n");
  add_song(lib,construct_song("Black Sabbath","Black Sabbath"));
  add_song(lib,construct_song("Paranoid","Black Sabbath"));
  add_song(lib,construct_song("It's Hip to Be Square","Huey Lewis & the News"));
  add_song(lib,construct_song("Highway to Hell","AC/DC"));
  
  printf("\n=====================\n");
  printf("testing clear_library:\n");
  clear_lib(lib);
  
  printf("Cleared Library: \n");
  print_library(lib);
  
  printf("\n==========  readding songs (again)  ===========\n");
  add_song(lib,construct_song("Black Sabbath","Black Sabbath"));
  add_song(lib,construct_song("Paranoid","Black Sabbath"));
  add_song(lib,construct_song("It's Hip to Be Square","Huey Lewis & the News"));
  add_song(lib,construct_song("Highway to Hell","AC/DC"));
  print_library(lib);
  
  printf("=====================\n");
  printf("testing shuffled_list:\n");
  
  struct song_node *shuff = shuffled_list(lib,2);
  print_list(shuff);
  
  return 0;
}
