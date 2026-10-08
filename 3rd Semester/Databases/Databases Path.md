### Lab 1

How to start the database:
Option 1 (with terminal):
1. docker start sqledge (in Mac Terminal)
2. docker ps (Look for `sqledge` in the list and check if the STATUS says "Up")
3. open DataGrip

Option 2 (with visuals):
1. open docker app -> containers -> run sqledge
2. open DataGrip

How to stop the database:
1. right click on Docker SQL Server (connection) -> deactivate 
2. docker stop sqledge / docker app -> containers -> stop sqledge
3. close DataGrip
4. close docker desktop

A1:
Lab 1. Database Design 
• assigned: week 1; due: week 3
Imagine a simple application that requires a database. Represent the 
application data in a relational structure and implement the structure in 
a SQL Server database. The database must contain at least: 10 tables, 
two 1:n relationships, one m:n relationship.
Before you start working, send an e-mail to the lab instructor with the 
application for which you want to create the database, along with a short 
description. In case of conflicts, first in the list wins, so check existing 
entries here to make sure your topic hasn't been chosen