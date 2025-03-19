The syntax is mostly correct, but there are some issues:
The second call to getline(myfile, title); inside the loop could cause incorrect reading of the title.
The constructor signature mismatches data types (ISBN should be string instead of int to avoid leading-zero truncation issues).
Using myfile.ignore(); without specifying the number of characters could cause unexpected behavior.

🔹 Improvements:

Fix the getline() issue to ensure the title is read correctly.
Change ISBN to a string to handle cases where the number starts with 0.
Use myfile.ignore(numeric_limits<streamsize>::max(), '\n'); instead of just myfile.ignore();.
