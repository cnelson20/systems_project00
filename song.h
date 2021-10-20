struct song_node;
struct song_node *construct_song(char *n, char *art);
int compare_songs(struct song_node *a, struct song_node *b);
struct song_node *insert_front(struct song_node *head, struct song_node *new);
struct song_node * insert_node(struct song_node *head, struct song_node *new);
int  strcasecmp(const char *, const char *);
int print_list(struct song_node *head);
int tolower(unsigned char ch);
int main();
