#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "song.h"

struct song_node *insert_front(struct song_node *head,struct song_node *new) {
  new->next = head;
  return new;
}
struct song_node *insert_node(struct song_node *head, struct song_node *new) {
  if (head == NULL) {
	new->next = NULL;
	return new;
  }
  struct song_node *copy = head;
  while (copy->next) {
    if (compare_songs(copy,new) > 0) {
      if (copy == head) {
	insert_front(head,new);
	return new;
      }
      return head;
    }
    copy = copy->next;
  }
  if (compare_songs(copy,new) > 0) {
    insert_front(copy,new);
    return new;
  } else {
    copy->next = new;
    return head;
  }
}

struct song_node *construct_song(char *n, char *art) {
  struct song_node *s = malloc(sizeof(struct song_node));
  strncpy(s->name,n,SONG_NAMELENGTH - 1);
  strncpy(s->artist,art,SONG_ARTISTLENGTH - 1);
  s->next = NULL;

  return s;
}
int print_song(struct song_node *s) {
  if (s == NULL) {
	printf("NULL\n");
	return 0;
  }
  printf("%s by %s\n",s->name,s->artist);
  return 0;
}
int print_list(struct song_node *head) {
  struct song_node *c = head;
  printf("[ "); 
  while (head) {
	if (c != head) {printf(" | ");}
    printf("%s: %s",head->artist,head->name);
    head = head->next;
  }
  printf(" ]\n");
  return 0;
}

struct song_node *find_song(struct song_node *list,char *name, char *artist) {
  while (list) {
    if (strcasecmp(list->artist,artist) || strcasecmp(list->name,name)) {
      list = list->next;
    } else {
      return list;
    }
  }
  return NULL;
}
struct song_node *find_first_song(struct song_node *list,char *artist) {
  while (list) {
    if (strcasecmp(list->artist,artist)) {
      list = list->next;
    } else {
      return list;
    }
  }
  return NULL;
}

struct song_node *remove_song(struct song_node *list,char *name, char *artist) {
	struct song_node *dup = list;
	if ((!strcasecmp(dup->name,name)) && (!strcasecmp(dup->artist,artist)))  {
		dup = list->next; 
		free(list);
		return dup;
	}
	while (dup->next->next) {
		if ((!strcasecmp(dup->next->name,name)) && (!strcasecmp(dup->next->artist,artist))) {
			struct song_node *temp = dup->next;			
			dup->next = temp->next;
			free(temp);
			return list;
		}
		dup = dup->next;
	}
	if ((!strcasecmp(dup->next->name,name)) && (!strcasecmp(dup->next->artist,artist))) {
		struct song_node *temp = dup->next;			
		dup->next = temp->next;
		free(temp);
	}
	return list;
	
}

struct song_node *free_list(struct song_node *list) {
	if (list->next) {free_list(list->next);}
	list->next = NULL;
	free(list);
	return NULL;
}

struct song_node *random_song(struct song_node *list) {
  struct song_node *copy = list;
  int length = 1;
  while (copy = copy->next) {length++;}
  int r = rand() % length;
  while (r) {
    list = list->next;
    r--;
  }
  return list;
}

int strcasecmp(const char *s1, const char *s2) {
    const unsigned char *us1 = (const u_char *)s1,
                        *us2 = (const u_char *)s2;

    while (tolower(*us1) == tolower(*us2++))
        if (*us1++ == '\0')
            return (0);
    return (tolower(*us1) - tolower(*--us2));
}

int compare_songs(struct song_node *a, struct song_node *b) {
  int i;
  i = strcasecmp(a->artist,b->artist);
  if (i != 0) {return i;}
  return strcasecmp(a->name,b->name);
}
