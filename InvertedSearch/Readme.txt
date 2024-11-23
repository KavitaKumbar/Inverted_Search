INTRODUCTION:

An inverted index is an index data structure storing a mapping from content, such as words 
or numbers, to its locations in a database file, or in a document or a set of documents. 
The purpose of an inverted index is to allow fast full text searches, at the cost of increased 
processing when a document is added to the database. The inverted file may be the database file 
itself, rather than its index. It is the most popular data structure used in document retrieval 
systems, used on a large scale for example in search engines.


Forward Indexing - It is a data structure that stores mapping from documents to words
                    i.e. directs you from document to word.
                    Eg. - Table of contents in book.
Inverted Indexing - It is a data structure that stores mapping from words to documents or set of documents 
                    i.e. directs you from word to document.
                    Eg. - Index at the back of the book.
    
OPERATIONS :
1   :  Create Database
2   :  Display Database
3   :   Search Database
4   :  Update Database
5   :  Save Database

PRINTING PATTERN :
Display the index number and details as follows -> [index_no] <word> <file_count> "<file_name> <word_count>"(file count times)

SAVING PATTERN :
Store the contents in given pattern: #<index_no>;<word>;<file_count>;<file_name>;<word_count>#