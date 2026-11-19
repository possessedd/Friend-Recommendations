# Friend Recommendations

A desktop application written in C++/CLI (Windows Forms) that models a social network as a graph and recommends new friends based on mutual connections.

## Features

- Add, delete and rename users
- Create friendships between users (connections are mutual)
- Friend recommendations with a count of mutual friends
- Validation against duplicates, empty names and self-friendship

## How it works

The network is stored as an undirected graph using an adjacency list: `Dictionary<String^, List<String^>^>`, where each key is a user and the value is the list of that user's friends.

Recommendations follow the "friends of friends" approach: for the selected user, the program goes through the friends of their friends and collects everyone who is not yet a friend. For each candidate, the number of mutual friends is counted.

## Tech stack

- C++/CLI
- Windows Forms, .NET Framework 4.7.2
- Visual Studio 2022 (toolset v143)

## Getting started

1. Open `FriendRecommendations.sln` in Visual Studio with the C++/CLI component installed.
2. Select the `Release | x64` configuration.
3. Build the solution (`Build → Build Solution`) and run it.

## Possible improvements

- Sort recommendations by the number of mutual friends
- Remove friendships
- Save and load the graph from a file
