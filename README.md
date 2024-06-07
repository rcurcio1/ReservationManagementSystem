# Community Center Management System
Software to manage reservations and purchase of tickets for the events hosted at the Newton Community Center

## Login Information
At the beginning of the porgram you will be prompted to login with a username and password. The following users have can be logged into, each with their own type as show in the table.
| User Type | Username | Password | 
| --------- | -------- | -------- |
| City      | CityRec  | password |
| Resident  | rosscurcio | password2 |
| Non-Resident | joecurcio | password3 |

To add more users, edit the "users.txt" file.
## Implementation Details
### Confirmation
I decided that each event would have a field showing whether it was confirmed or not. An event is confirmed when the current day is within 7 days of the day the event is scheduled for, or if the event is payed for in full. I allowed cities to book times over events that have not been confirmed yet. City reservations are immediately confirmed. Users can only buy tickets to events that have been confirmed.
### Credit
I decided that each user would have a field representing their credit. Their credit represents their buying power at any given time. They cannot buy a ticket for an event, or pay off an event if they do not have enough credit. When a user makes a reservation, it will fail if they do not have enough money for the service fee. When a user sells a ticket, their event gets cancelled, or an event they have a ticket to gets cancelled, that appropriate funds are added to their credit. A user on a waitlist will not be able to be granted a ticket if they do not have the credit to purchase it. A user can add to their credit at any time from the main menu.
### Days
I represent the current day in the program using the TODAY_MONTH and TODAY_DAY fields in main.cpp. These can be changed to reflect any other day of the year. This date is what is used to find events on or near today, and to confirm whether an event is within 7 days of today.
### Save Information For Events
Events are saved automatically in "events.txt", but that can be changed using the EVENT_FILE field in main.cpp. Each line in the file represents an event. Each line must contain in order:

1. Event name (string)
2. Organizer (must be a username)
3. Month (int)
4. Day (int)
5. Start Time (string i.e. 7pm)
6. End Time (string i.e. 7pm)
7. Open to non-residents (boolean)
8. Ticket cost (int)
9. Tickets remaining (int)
10. Amount owed (int)
11. Confirmed (boolean)
12. Private (boolean)
13. Layout (string -> wedding, lecture, dance, or meeting)
14. Any number of usernames on the waitlist
### Save Information For Users
Users are saved automatically in "users.txt", but that can be changed by using the USER_FILE field in main.cpp. Each line in the file represents a user. Each line must contain in order:

1. User type (C for city, R for resident, N for non-resident)
2. Username (unique string)
3. Password (string)
4. Credit (int)
5. Any number of event names that the user has tickets for
# Running the Program
The program gives great instructions for how to use it within the program, so below is just a general outline of what each function does.
## Login
Use the login information above to log in to the program as a specific user. 
## Menu
### Quit
Quit the program entirely
### View event schedule
View events for this day, this week, or view all events
### Request Reservation
Try to reserve a new event
### Make payment
Make any outstanding payments on events
### Cancel reservation
Cancel an event that this user previously reserved
### Purchase tickets
Purchase a ticket for an event of your choosign
### Cancel tickets
Return a ticket for an event you previously bought one for
### Transfer money
Add money to the credit of this user
### Logout
Logout of this user
