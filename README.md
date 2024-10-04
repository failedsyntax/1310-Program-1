# CSC-1310 Program 1
### Mock Spotify Backend Library
#### Authors: Jackson, Derek, Ryan

### How-to:
1. Download and extract all of the files into a folder
2. Compile the program with cli or vscode (g++ *.cpp -o prog.exe)
3. Once the compiler finishes, use <b>./prog.exe</b> to run the program
4. From there, use any inputs and their proper requirements to utilize the program correctly

### Importing Songs:
- There is a special formatting required in order to import songs
    - The entire format is on one line, each song separated by a new line
- Format:
    - <b>TITLE</b>#<b>ARTIST</b>#<b>DURATION IN (x:xx)</b>#<b>YEAR</b>#<b>RATING</b>
    - Example:
        - Homecoming#Kanye West & Chris Martin#3:23#2007#4.5
- Songs will be exported in the same format
