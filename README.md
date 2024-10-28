# Project 1a : Boggle Solver (in C)

## How to compile

To compile `spellcheck`

```
make spellcheck
```

To compile `onePlayerBoggle`

```
make onePlayerBoggle
```

## Testing using ./test.sh

Note the test file may take some time to run because of `valgrind`. If you are completing this project on replit, this may be quite, quite slow. I recommend you use smaller dictionaries and test different aspects of your program and avoid simply testing with `./teset.sh`

## Help Received

Please document any help you received in completing this lab. Note that the what you submit should be your own work. Refer to the syllabus for more details. 

I recieved help from Marlee during her office hours, as my code had a lot of memory errors. She was super great at helping me fix the these erors.

## Describe your work

Please provide a short description of your programming progress

I started on the hashmap and linkedlist coding portions. I didn't find them to be particularly difficult, but I definitely spent more time on the hashmap resize portion. In the resize function, I doubled the size of the hashmap and rehashed all of the nodes in the former hashmap to the new hashmap. Then, I went through the old array of buckets and deleted them as I rehashed the nodes to the new hashmap. This was definitely the most difficult part in creating the hashmap and linked lists. 
The next challenge was building the boggle function. First, we needed to open the dictionary, read it in, and make all of our words in the dictionary capital case. We did this using pointer arithmetic. Finally, we set the bg->dict = dictionary, where dictionary is the hashmap of words that we had just created. The next thing we had to do was return all the words we found by creating a linked list. We iterated through our entire hashmap, pushed all of these found words into a linked list, and then deleted that hashmap since those words were a linked list. We returned the linked list of words.
Finally, we checked the edge cases, string copied the last word into the curent word, checked if the next letter we were adding was a Q, added a U if so, and then added the word we created in the hashmap. Finally we updated the visited variable by incrementing it by 1. 


