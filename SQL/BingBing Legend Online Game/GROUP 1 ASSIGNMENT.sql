
--DDL
CREATE DATABASE BINGBING_LEGEND_ONLINE_GAME;

USE BINGBING_LEGEND_ONLINE_GAME;

CREATE TABLE Player
(
Username varchar(20)NOT NULL,
Player_id varchar(7) PRIMARY KEY,
Email_address varchar(50) NOT NULL,
Total_amount_of_battlepoints_collected int NOT NULL,
Total_diamonds_collected int NOT NULL,
Player_online_status varchar(10) NOT NULL,
Active_player varchar(15) NOT NULL,
Player_global_level int NOT NULL,
Heros_current_level int NOT NULL,
);


CREATE TABLE PLAYER_HERO
(
Purchased_Date DATE NOT NULL,
Player_hero_id varchar(6) PRIMARY KEY,
Heros_levels int NOT NULL,
Purchased_Time time NOT NULL,
Player_id varchar(7) NOT NULL,
Hero_id varchar(6) NOT NULL,
);


CREATE TABLE HERO
(
Hero_id varchar(6) PRIMARY KEY,
Hero_name varchar(15) NOT NULL,
Hero_role varchar(10) NOT NULL,
Hero_specialty varchar(20) NOT NULL,
H_Battlepoints int NOT NULL,
H_Diamonds int NOT NULL,
);

CREATE TABLE SKIN
(
Skin_name varchar(20) NOT NULL,
Skin_id varchar(5) PRIMARY KEY,
S_Battlepoints int NOT NULL,
S_Diamonds int NOT NULL,
Hero_id varchar (6) NOT NULL,
);

CREATE TABLE TEAM
(
TeamName varchar(50) NOT NULL,
TeamID varchar(6) PRIMARY KEY,
Game_id varchar(6) NOT NULL,
Game_mode_id varchar (5) NOT NULL,
Player_hero_id varchar(6) NOT NULL,
);


CREATE TABLE GAME
(
Game_id varchar(6) PRIMARY KEY,
Game_date DATE NOT NULL,
Game_results varchar(6) NOT NULL,
Game_Time TIME NOT NULL,
);

CREATE TABLE GAME_MODE
(
Game_mode_id varchar(5) PRIMARY KEY,
Game_mode_name varchar(20) NOT NULL,
);

CREATE TABLE Ownskin
(
Ownskin_ID varchar (7) PRIMARY KEY,
Player_id varchar(7) NOT NULL,
Skin_id varchar(5) NOT NULL,
)

--Foreign Keys
ALTER TABLE PLAYER_HERO
ADD CONSTRAINT FKPlayer_ID
FOREIGN KEY (Player_id) REFERENCES Player;

ALTER TABLE PLAYER_HERO
ADD CONSTRAINT FKHero_ID
FOREIGN KEY (Hero_id) REFERENCES HERO;

ALTER TABLE SKIN
ADD CONSTRAINT FK1Hero_ID
FOREIGN KEY (Hero_id) REFERENCES HERO;

ALTER TABLE TEAM
ADD CONSTRAINT FKGame_id
FOREIGN KEY (Game_id) REFERENCES GAME;

ALTER TABLE TEAM
ADD CONSTRAINT FKGame_mode_id
FOREIGN KEY (Game_mode_id) REFERENCES GAME_MODE;

ALTER TABLE TEAM
ADD CONSTRAINT FKPlayer_hero_id
FOREIGN KEY (Player_hero_id) REFERENCES PLAYER_HERO;

ALTER TABLE Ownskin
ADD CONSTRAINT FK1Player_id
FOREIGN KEY (Player_id) REFERENCES Player;

ALTER TABLE Ownskin
ADD CONSTRAINT FK1Skin_id
FOREIGN KEY (Skin_id) REFERENCES Skin;



INSERT INTO Player 
(Username, Player_id, Email_address, Total_amount_of_battlepoints_collected, 
Total_diamonds_collected , Player_online_status, Active_player, Player_global_level,Heros_current_level)
VALUES 
('Wade Wilson', '0001', 'wadewilson@gmail.com',1199, 120, 'Online', 'Active', 122, 9 ),
('Steve Rogers', '0002', 'steve10@gmail.com', 2330, 215, 'Offline', 'Not active', 67, 8 ),
('Kyle Jordan', '0003', 'kjordan@gmail.com', 1220, 112, 'Online', 'Active', 124,6 ),
('Samson Peter', '0004', 'samsonpeter@gmail.com', 2325, 113, 'Online', 'Active', 213,12 ),
('Mary Koh ', '0005', 'marykoh@gmail.com', 2299, 422, 'Offline', 'Not active', 199,10 ),
('Steve Jacob', '0006', 'steve17@gmail.com', 2115, 233, 'Online', 'Active', 62, 14);

select * from player;


INSERT INTO HERO
(Hero_id,Hero_name,Hero_role,Hero_specialty,H_Battlepoints,H_Diamonds)
VALUES
('H001', 'Harley',  'Nuker', 'Charge', 30, 10),
('H002', 'Lesley',  'Assassin', 'Burst', 40, 15),
('H003', 'Gusion',  'Fighter', 'Reap', 10, 5),
('H004', 'Venic',  'Initiator', 'Regen', 5, 3),
('H005', 'Carmilla',  'Mage', 'Charge', 4, 2),
('H006', 'Cecilion', 'Marksman', 'Crowd Control', 35, 12);

select * from HERO;


INSERT INTO PLAYER_HERO
(Purchased_Date,Player_hero_id,Heros_levels,Purchased_Time,Player_id,Hero_id)
VALUES
('01/02/2020', 'PH5001', 5, '02:03:02', '0001', 'H001'),
('03/02/2020', 'PH5002', 4, '02:04:02', '0002', 'H002'),
('10/02/2020', 'PH5003', 2, '05:26:08','0003', 'H003'),
('12/02/2020', 'PH5004', 6, '07:28:08','0004', 'H004'),
('12/02/2020', 'PH5005', 7, '08:02:07','0005','H005'),
('10/02/2020', 'PH5006', 3, '05:26:09','0006', 'H006'),
('01/02/2020', 'PH5007', 8, '02:03:02','0001', 'H001'),
('03/02/2020', 'PH5008', 11, '02:04:02','0002', 'H002' ),
('10/02/2020', 'PH5009', 20, '05:26:08','0003', 'H003');

SELECT * FROM PLAYER_HERO;


INSERT INTO SKIN
(Skin_name ,Skin_id ,S_Battlepoints ,S_Diamonds ,Hero_id)
VALUES
('Joker', 'S021', 30, 10, 'H001'),
('Werewolf', 'S022', 10, 5, 'H002'),
('Iron', 'S023', 15, 8, 'H001'),
('Superman', 'S024', 50, 30, 'H003'),
('Ironman', 'S025', 60, 35, 'H004'),
('Bumblebee', 'S026', 70, 50, 'H005' );

SELECT * FROM SKIN; 

INSERT INTO GAME
(Game_id ,Game_date ,Game_results,Game_Time)
VALUES
('G031', '03/02/2020', 'Won', '05:02:21'),
('G032', '08/02/2020', 'Lost', '09:08:35'),
('G033', '08/02/2020', 'Lost', '07:09:33'),
('G034', '12/02/2020', 'Won', '08:04:23'),
('G035', '09/02/2020', 'Won', '08:04:05'),
('G036', '07/02/2020', 'Lost', '07:05:04');

SELECT * FROM GAME;

INSERT INTO GAME_MODE
(Game_mode_id ,Game_mode_name )
VALUES 
('GM041', 'Advance'),
('GM042', 'Insurgency'),
('GM043', 'Invasion'),
('GM044', 'Destruction'),
('GM045', 'Territory Control'),
('GM046', 'Skirmish');

SELECT * FROM GAME_MODE;


INSERT INTO TEAM
(TeamName ,TeamID ,Game_id ,Game_mode_id ,Player_hero_id)
VALUES 
('Super Power', 'T061','G031', 'GM041','PH5001'),
('Black Panthers', 'T062','G032','GM042', 'PH5002'),
('Dominators', 'T063','G033','GM043', 'PH5003'),
('Guns for Hire', 'T064','G034', 'GM044', 'PH5004'),
('Fire Starters', 'T065','G035','GM045','PH5005'),
('No Fear', 'T066','G036', 'GM046', 'PH5006');

SELECT * FROM TEAM;


INSERT INTO Ownskin
(Ownskin_ID ,Player_id ,Skin_id)
VALUES
('OS1','0001','S021'),
('OS2','0001','S021'),
('OS3','0001','S021'),
('OS4','0001','S021'),
('OS5','0001','S021');

SELECT * FROM Ownskin;

----DML
--Student 1
---Question 1
select Username, Email_address
from Player 
where Username LIKE '%er' or Username LIKE '%on%'
ORDER BY Username ASC;

--Question 2
select Username, Heros_current_level, player.Player_id 
from PLAYER_HERO inner join Player on Player.Player_id = PLAYER_HERO.Player_id
WHERE Heros_levels > 3
order by player.Player_id;

--Question 3
select P.Player_id, P.Username, H.Hero_id, H.Hero_name, S.Heros_levels
FROM  PLAYER_HERO S
INNER JOIN HERO H ON S.HERO_id = H.Hero_id
INNER JOIN PLAYER P on P.Player_id = S.Player_id
where P.Username = 'Wade Wilson';

--Student 2
---Question 1
select Game_id, Game_date
from GAME
where Game_date BETWEEN '2020-02-01' AND '2020-02-29'
ORDER BY Game_date ASC;

--Question 2
select Username, Email_address from Player
Where Player_id in (select distinct Player_id from PLAYER_HERO where Hero_id in 
(Select Hero_id from Hero where Hero_role = 'Assassin'));

--Question 3
select distinct H.Hero_id, Hero_name
from SKIN S INNER JOIN HERO H on H.Hero_id = S.Hero_id
where S_Battlepoints > (Select avg(S_Battlepoints) from Skin)
ORDER BY Hero_name asc;

--Student 3
--Question 1
select Username, Email_Address, Total_diamonds_collected
from player
where Total_diamonds_collected >= 15
Order by Username;

--Question 2
select S.Hero_id , H.Hero_name, COUNT (S.Skin_id) as 'Total Skins'
from Hero H INNER JOIN Skin S on H.Hero_id = S.Hero_id
GROUP BY S.Hero_id, H.Hero_name;

--Question 3
Select PH.Player_id, P.Player_global_level, 
count (T.TeamID) as 'Total Games Played', P.Player_global_level
from Player P INNER JOIN PLAYER_HERO PH ON P.Player_id = PH.Player_id 
INNER JOIN TEAM T ON PH.Player_hero_id = T.Player_hero_id
INNER JOIN GAME G ON T.Game_id = G.Game_id 
where Player_global_level > 5
group by PH.Player_id, P.Player_global_level 
having PH.Player_id in (SELECT GamesPlayed.Player_id from 
						(select PH.Player_id, COUNT(TeamID) TimesPlayed from Team T
						inner join PLAYER_HERO PH ON T.Player_hero_id = PH.Player_hero_id
						GROUP BY PH.Player_id) GamesPlayed where TimesPlayed >3);

--Student 4
--Question 1
select Username, Total_amount_of_battlepoints_collected
from player
where Total_amount_of_battlepoints_collected = (select max(Total_amount_of_battlepoints_collected) from player)
order by Username ASC;

--Question 2
select T.Game_mode_id, M.Game_mode_name, 
Count (Game_id) as 'Total_games_played'
from TEAM T inner join GAME_MODE M on M.Game_mode_id = T.Game_mode_id
GROUP BY T.game_mode_id, M.Game_mode_name
ORDER BY Total_games_played DESC;

--Question 3
select ph.player_id, ph.hero_id, h.hero_name, count (ph.hero_id) as used
from PLAYER_HERO PH INNER JOIN TEAM T ON PH.Player_hero_id = T.Player_hero_id
INNER JOIN HERO H ON PH.Hero_id = H.Hero_id
WHERE PH.Player_id = (SELECT Player_id FROM Player where username = 'Steve Rogers')
GROUP BY PH.Hero_id, PH.Player_id, H.Hero_Name
HAVING COUNT (PH.Hero_id) in (select max(used) 
	from ( select ph.hero_id, count (ph.hero_id) used from PLAYER_HERO PH 
	INNER JOIN TEAM T on PH.Player_hero_id = T.Player_hero_id
	INNER JOIN HERO H ON PH.Hero_id = H.Hero_id
	WHERE PH.Player_id= (SELECT Player_id FROM Player WHERE Username = 'Steve Rogers')
	GROUP BY PH.Hero_id) MaxCount);


--Student 5
--Question 1
select Game_id, Game_date
from GAME
where NOT Game_date BETWEEN '2020-02-01' AND '2020-02-29'
ORDER BY Game_date ASC;

--Question 2
--List the hero id, hero name and total number of heroes belong to each hero
select COUNT(H.Hero_id) as Total_hero_number, H.Hero_name, S.Hero_id
FROM  PLAYER_HERO S
INNER JOIN HERO H ON S.HERO_id = H.Hero_id
INNER JOIN PLAYER P on P.Player_id = S.Player_id
GROUP BY  Hero_name, S.Hero_id;

--Question 3
--List the ids and names of the most used heroes for the player named ‘Kyle Jordan’
select ph.player_id, ph.hero_id, h.hero_name, count (ph.hero_id) as used
from PLAYER_HERO PH INNER JOIN TEAM T ON PH.Player_hero_id = T.Player_hero_id
INNER JOIN HERO H ON PH.Hero_id = H.Hero_id
WHERE PH.Player_id = (SELECT Player_id FROM Player where username = 'Kyle Jordan')
GROUP BY PH.Hero_id, PH.Player_id, H.Hero_Name
HAVING COUNT (PH.Hero_id) in (select max(used) 
	from ( select ph.hero_id, count (ph.hero_id) used from PLAYER_HERO PH 
	INNER JOIN TEAM T on PH.Player_hero_id = T.Player_hero_id
	INNER JOIN HERO H ON PH.Hero_id = H.Hero_id
	WHERE PH.Player_id= (SELECT Player_id FROM Player WHERE Username = 'Kyle Jordan')
	GROUP BY PH.Hero_id) MaxCount);


