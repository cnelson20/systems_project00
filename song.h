struct song_node;
struct song_node *construct_song(char *n, char *art);
int compare_songs(struct song_node *a, struct song_node *b);
struct song_node *insert_front(struct song_node *head, struct song_node *new);
struct song_node * insert_node(struct song_node *head, struct song_node *new);
int print_song(struct song_node *s);
int print_list(struct song_node *head);
struct song_node *find_song(struct song_node *list,char *name, char *artist);
struct song_node *find_first_song(struct song_node *list,char *artist);
struct song_node *random_song(struct song_node *list);
struct song_node *remove_song(struct song_node *list,char *name, char *artist);
struct song_node *free_list(struct song_node *list);

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};
