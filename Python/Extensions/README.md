# File Extensions

Web browsers rely on media types, formerly known as MIME types, to determine how to display files that live on the web. 
When you download a file from a web server, that server sends an HTTP header, along with the file itself, indicating the file’s media type. 
For instance, the media type for a GIF is image/gif, and the media type for a JPEG is image/jpeg. 
To determine the media type for a file, a web server typically looks at the file’s extension, mapping one to the other.


## The Program:

The user is prompted for the name of a file.  
If the file name ends, case-insensitively, in any of the following suffixes, the file's media type is outputted.
* .gif
* .jpg
* .jpeg
* .png
* .pdf
* .txt
* .zip    
  
If the file’s name ends with some other suffix or has no suffix at all, 'application/octet-stream' is instead outputted, which is a common default.

**DEMO:**

```
$ python extensions.py
File name? Tree.jpg
image/jpg
$ python extensions.py
File name? table.pdf
application/pdf
```
