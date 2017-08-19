-- MySQL dump 10.13  Distrib 5.5.54, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: suppliers
-- ------------------------------------------------------
-- Server version	5.5.54-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary table structure for view `inner_join_view`
--

DROP TABLE IF EXISTS `inner_join_view`;
/*!50001 DROP VIEW IF EXISTS `inner_join_view`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `inner_join_view` (
  `Pname` tinyint NOT NULL,
  `QTY` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `parts`
--

DROP TABLE IF EXISTS `parts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `parts` (
  `Pid` int(4) NOT NULL AUTO_INCREMENT,
  `Pname` varchar(20) DEFAULT NULL,
  `Colour` varchar(20) DEFAULT NULL,
  `Weight` varchar(20) DEFAULT NULL,
  `City` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Pid`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `parts`
--

LOCK TABLES `parts` WRITE;
/*!40000 ALTER TABLE `parts` DISABLE KEYS */;
INSERT INTO `parts` VALUES (1,'gear','black','200gms','pune'),(2,'axle','black','200gms','mumbai'),(3,'bolt','black','200gms','mumbai'),(4,'wheels','silver','1.5kg','Tokyo');
/*!40000 ALTER TABLE `parts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projects`
--

DROP TABLE IF EXISTS `projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `projects` (
  `Jid` int(4) NOT NULL AUTO_INCREMENT,
  `Jname` varchar(20) DEFAULT NULL,
  `City` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Jid`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projects`
--

LOCK TABLES `projects` WRITE;
/*!40000 ALTER TABLE `projects` DISABLE KEYS */;
INSERT INTO `projects` VALUES (1,'Drone','London'),(2,'Library management','London'),(3,'Super highway','China'),(4,'Hyperloop','Pune'),(5,'LIGO','India');
/*!40000 ALTER TABLE `projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shipment`
--

DROP TABLE IF EXISTS `shipment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `shipment` (
  `Pid` int(11) DEFAULT NULL,
  `Sid` int(11) DEFAULT NULL,
  `QTY` int(11) DEFAULT NULL,
  `Jid` int(4) DEFAULT NULL,
  KEY `Pid` (`Pid`),
  KEY `Sid` (`Sid`),
  KEY `Jid` (`Jid`),
  CONSTRAINT `shipment_ibfk_1` FOREIGN KEY (`Pid`) REFERENCES `parts` (`Pid`),
  CONSTRAINT `shipment_ibfk_2` FOREIGN KEY (`Sid`) REFERENCES `suplr` (`Sid`),
  CONSTRAINT `shipment_ibfk_3` FOREIGN KEY (`Jid`) REFERENCES `projects` (`Jid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shipment`
--

LOCK TABLES `shipment` WRITE;
/*!40000 ALTER TABLE `shipment` DISABLE KEYS */;
INSERT INTO `shipment` VALUES (1,1,4,1),(2,2,7,1),(3,2,4,5),(1,4,8,4),(2,5,2,3),(1,1,2,3),(4,1,4,1);
/*!40000 ALTER TABLE `shipment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `suplr`
--

DROP TABLE IF EXISTS `suplr`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `suplr` (
  `Sid` int(4) NOT NULL AUTO_INCREMENT,
  `Sname` varchar(20) DEFAULT NULL,
  `Status` varchar(20) DEFAULT NULL,
  `City` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Sid`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `suplr`
--

LOCK TABLES `suplr` WRITE;
/*!40000 ALTER TABLE `suplr` DISABLE KEYS */;
INSERT INTO `suplr` VALUES (1,'verma','good','pune'),(2,'sharma','good','mumbai'),(3,'kishan','okay','ahmednagar'),(4,'Mackenzie','Good','London'),(5,'Sup liar','good','London'),(6,'Queen Elizabeth','Good','London');
/*!40000 ALTER TABLE `suplr` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `inner_join_view`
--

/*!50001 DROP TABLE IF EXISTS `inner_join_view`*/;
/*!50001 DROP VIEW IF EXISTS `inner_join_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`blah`@`%` SQL SECURITY DEFINER */
/*!50001 VIEW `inner_join_view` AS select `parts`.`Pname` AS `Pname`,`shipment`.`QTY` AS `QTY` from (`parts` join `shipment` on((`parts`.`Pid` = `shipment`.`Pid`))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES ;

-- Dump completed on 2017-07-19 11:25:17



Database changed
mysql> create table projects (Jid int(4), Jname varchar(20), City varchar(20));
Query OK, 0 rows affected (0.07 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> desc shiopment;
ERROR 1146 (42S02): Table 'suppliers.shiopment' doesn't exist
mysql> desc shipment;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| Pid   | int(11) | YES  | MUL | NULL    |       |
| Sid   | int(11) | YES  | MUL | NULL    |       |
| QTY   | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | YES  |     | NULL    |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table projects modify column Jid int primary key;
Query OK, 0 rows affected (0.17 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(11)     | NO   | PRI | NULL    |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table projects modify column Jid int(4);
Query OK, 0 rows affected (0.04 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | NO   | PRI | 0       |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | NO   | PRI | 0       |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table projects modify column Jid int(4) auto_increment;
Query OK, 0 rows affected (0.17 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+----------------+
| Field | Type        | Null | Key | Default | Extra          |
+-------+-------------+------+-----+---------+----------------+
| Jid   | int(4)      | NO   | PRI | NULL    | auto_increment |
| Jname | varchar(20) | YES  |     | NULL    |                |
| City  | varchar(20) | YES  |     | NULL    |                |
+-------+-------------+------+-----+---------+----------------+
3 rows in set (0.00 sec)

mysql> insert into projects (Jname, City) values ("Super highway","China")
    -> ;
Query OK, 1 row affected (0.05 sec)

mysql> insert into projects (Jname, City) values ("LIGO","India")
    -> ;
Query OK, 1 row affected (0.05 sec)

mysql> select * from projects;
+-----+--------------------+--------+
| Jid | Jname              | City   |
+-----+--------------------+--------+
|   1 | Drone              | London |
|   2 | Library management | London |
|   3 | Super highway      | China  |
|   4 | Hyperloop          | Pune   |
|   5 | LIGO               | India  |
+-----+--------------------+--------+
5 rows in set (0.00 sec)

mysql> select * from projects where City='London';
+-----+--------------------+--------+
| Jid | Jname              | City   |
+-----+--------------------+--------+
|   1 | Drone              | London |
|   2 | Library management | London |
+-----+--------------------+--------+
2 rows in set (0.00 sec)

mysql> alter table suplr modify column Sid int(4) auto_increment;
Query OK, 3 rows affected (0.20 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> desc suplr;
+--------+-------------+------+-----+---------+----------------+
| Field  | Type        | Null | Key | Default | Extra          |
+--------+-------------+------+-----+---------+----------------+
| Sid    | int(4)      | NO   | PRI | NULL    | auto_increment |
| Sname  | varchar(20) | YES  |     | NULL    |                |
| Status | varchar(20) | YES  |     | NULL    |                |
| City   | varchar(20) | YES  |     | NULL    |                |
+--------+-------------+------+-----+---------+----------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+--------+--------+------------+
| Sid | Sname  | Status | City       |
+-----+--------+--------+------------+
|   1 | verma  | good   | pune       |
|   2 | sharma | good   | mumbai     |
|   3 | kishan | okay   | ahmednagar |
+-----+--------+--------+------------+
3 rows in set (0.00 sec)

mysql> select * from shipment;
Empty set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> desc shipment;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| Pid   | int(11) | YES  | MUL | NULL    |       |
| Sid   | int(11) | YES  | MUL | NULL    |       |
| QTY   | int(11) | YES  |     | NULL    |       |
| Jid   | int(4)  | YES  | MUL | NULL    |       |
+-------+---------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> insert into shipment values(1,1,4, 1);
Query OK, 1 row affected (0.03 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
+------+------+------+------+
1 row in set (0.00 sec)

mysql> insert into shipment values(2,2,4, 1);
Query OK, 1 row affected (0.04 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    2 |    2 |    4 |    1 |
+------+------+------+------+
3 rows in set (0.00 sec)

mysql> update shipment set Pid=3 ,Jid=5 where Pid=2 and QTY=4;
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
+------+------+------+------+
3 rows in set (0.01 sec)

mysql> select * from suplr where Sid in (select Sid from shipment where Jid=1);
+-----+--------+--------+--------+
| Sid | Sname  | Status | City   |
+-----+--------+--------+--------+
|   1 | verma  | good   | pune   |
|   2 | sharma | good   | mumbai |
+-----+--------+--------+--------+
2 rows in set (0.00 sec)

mysql> insert into suplr(Sname, Status, City) values("Mackenzie", "Good", "London")
    -> ;
Query OK, 1 row affected (0.04 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> insert into suplr(Sname, Status, City) values("Queen Elizabeth", "Good", "London");
Query OK, 1 row affected (0.03 sec)

mysql> select * from suplr;
+-----+-----------------+--------+------------+
| Sid | Sname           | Status | City       |
+-----+-----------------+--------+------------+
|   1 | verma           | good   | pune       |
|   2 | sharma          | good   | mumbai     |
|   3 | kishan          | okay   | ahmednagar |
|   4 | Mackenzie       | Good   | London     |
|   5 | Sup liar        | good   | London     |
|   6 | Queen Elizabeth | Good   | London     |
+-----+-----------------+--------+------------+
6 rows in set (0.00 sec)

mysql> desc parts;
+--------+-------------+------+-----+---------+----------------+
| Field  | Type        | Null | Key | Default | Extra          |
+--------+-------------+------+-----+---------+----------------+
| Pid    | int(4)      | NO   | PRI | NULL    | auto_increment |
| Pname  | varchar(20) | YES  |     | NULL    |                |
| Colour | varchar(20) | YES  |     | NULL    |                |
| Weight | varchar(20) | YES  |     | NULL    |                |
| City   | varchar(20) | YES  |     | NULL    |                |
+--------+-------------+------+-----+---------+----------------+
5 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
+------+------+------+------+
3 rows in set (0.00 sec)

mysql> insert into shipment values(1,4,8,4);
Query OK, 1 row affected (0.04 sec)

mysql> insert into shipment values(2,5,2,3);
Query OK, 1 row affected (0.04 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
|    1 |    4 |    8 |    4 |
|    2 |    5 |    2 |    3 |
+------+------+------+------+
5 rows in set (0.01 sec)

mysql> insert into shipment values(1,1,2,3);
Query OK, 1 row affected (0.05 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
|    1 |    4 |    8 |    4 |
|    2 |    5 |    2 |    3 |
|    1 |    1 |    2 |    3 |
+------+------+------+------+
6 rows in set (0.00 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> select * from projects where Jid in (select Jid from shipment where Sid=1);
+-----+---------------+--------+
| Jid | Jname         | City   |
+-----+---------------+--------+
|   1 | Drone         | London |
|   3 | Super highway | China  |
+-----+---------------+--------+
2 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> select Colour from parts where Pid in (select Pid from shipment where Sid=1);
+--------+
| Colour |
+--------+
| black  |
+--------+
1 row in set (0.00 sec)

mysql> select Pname from parts union select Colour from parts;
+-------+
| Pname |
+-------+
| gear  |
| axle  |
| bolt  |
| black |
+-------+
4 rows in set (0.00 sec)
///////------------------------------------------
mysql> select distinct a.Colour from parts a, shipment b where a.Pid=b.Pid and Sid=1;
+--------+
| Colour |
+--------+
| black  |
| silver |
+--------+
2 rows in set (0.01 sec)

mysql> select distinct a.Colour from parts as a, shipment as b where a.Pid=b.Pid and Sid=1;
+--------+
| Colour |
+--------+
| black  |
| silver |
+--------+
2 rows in set (0.00 sec)
mysql> select p.Pname, q.Colour from parts p cross join parts as q ;
+--------+--------+
| Pname  | Colour |
+--------+--------+
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | silver |
| axle   | silver |
| bolt   | silver |
| wheels | silver |
+--------+--------+
16 rows in set (0.00 sec)

mysql> select p.Pname, q.City from parts p cross join parts as q ;
+--------+--------+
| Pname  | City   |
+--------+--------+
| gear   | pune   |
| axle   | pune   |
| bolt   | pune   |
| wheels | pune   |
| gear   | mumbai |
| axle   | mumbai |
| bolt   | mumbai |
| wheels | mumbai |
| gear   | mumbai |
| axle   | mumbai |
| bolt   | mumbai |
| wheels | mumbai |
| gear   | Tokyo  |
| axle   | Tokyo  |
| bolt   | Tokyo  |
| wheels | Tokyo  |
+--------+--------+
16 rows in set (0.00 sec)

mysql> 
mysql> select Jid,Sid from shipment group by Sid having count(Sid)>0;
+------+------+
| Jid  | Sid  |
+------+------+
|    1 |    1 |
|    1 |    2 |
|    4 |    4 |
|    3 |    5 |
+------+------+
4 rows in set (0.01 sec)

mysql> select Jid,Sid from shipment group by Sid having count(Sid)>1;
+------+------+
| Jid  | Sid  |
+------+------+
|    1 |    1 |
|    1 |    2 |
+------+------+
2 rows in set (0.00 sec)




-- Dump completed on 2017-07-14 12:15:07


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





Database changed
mysql> create table projects (Jid int(4), Jname varchar(20), City varchar(20));
Query OK, 0 rows affected (0.07 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> desc shiopment;
ERROR 1146 (42S02): Table 'suppliers.shiopment' doesn't exist
mysql> desc shipment;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| Pid   | int(11) | YES  | MUL | NULL    |       |
| Sid   | int(11) | YES  | MUL | NULL    |       |
| QTY   | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | YES  |     | NULL    |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table projects modify column Jid int primary key;
Query OK, 0 rows affected (0.17 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(11)     | NO   | PRI | NULL    |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)


mysql> alter table projects modify column Jid int(4);
Query OK, 0 rows affected (0.04 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | NO   | PRI | 0       |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> desc projects;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Jid   | int(4)      | NO   | PRI | 0       |       |
| Jname | varchar(20) | YES  |     | NULL    |       |
| City  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table projects modify column Jid int(4) auto_increment;
Query OK, 0 rows affected (0.17 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc projects;
+-------+-------------+------+-----+---------+----------------+
| Field | Type        | Null | Key | Default | Extra          |
+-------+-------------+------+-----+---------+----------------+
| Jid   | int(4)      | NO   | PRI | NULL    | auto_increment |
| Jname | varchar(20) | YES  |     | NULL    |                |
| City  | varchar(20) | YES  |     | NULL    |                |
+-------+-------------+------+-----+---------+----------------+
3 rows in set (0.00 sec)

mysql> insert into projects (Jname, City) values ("Super highway","China")
    -> ;
Query OK, 1 row affected (0.05 sec)

mysql> insert into projects (Jname, City) values ("LIGO","India")
    -> ;
Query OK, 1 row affected (0.05 sec)

mysql> select * from projects;
+-----+--------------------+--------+
| Jid | Jname              | City   |
+-----+--------------------+--------+
|   1 | Drone              | London |
|   2 | Library management | London |
|   3 | Super highway      | China  |
|   4 | Hyperloop          | Pune   |
|   5 | LIGO               | India  |
+-----+--------------------+--------+
5 rows in set (0.00 sec)

mysql> select * from projects where City='London';
+-----+--------------------+--------+
| Jid | Jname              | City   |
+-----+--------------------+--------+
|   1 | Drone              | London |
|   2 | Library management | London |
+-----+--------------------+--------+
2 rows in set (0.00 sec)

mysql> alter table suplr modify column Sid int(4) auto_increment;
Query OK, 3 rows affected (0.20 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> desc suplr;
+--------+-------------+------+-----+---------+----------------+
| Field  | Type        | Null | Key | Default | Extra          |
+--------+-------------+------+-----+---------+----------------+
| Sid    | int(4)      | NO   | PRI | NULL    | auto_increment |
| Sname  | varchar(20) | YES  |     | NULL    |                |
| Status | varchar(20) | YES  |     | NULL    |                |
| City   | varchar(20) | YES  |     | NULL    |                |
+--------+-------------+------+-----+---------+----------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+--------+--------+------------+
| Sid | Sname  | Status | City       |
+-----+--------+--------+------------+
|   1 | verma  | good   | pune       |
|   2 | sharma | good   | mumbai     |
|   3 | kishan | okay   | ahmednagar |
+-----+--------+--------+------------+
3 rows in set (0.00 sec)

mysql> select * from shipment;
Empty set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)


mysql> desc shipment;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| Pid   | int(11) | YES  | MUL | NULL    |       |
| Sid   | int(11) | YES  | MUL | NULL    |       |
| QTY   | int(11) | YES  |     | NULL    |       |
| Jid   | int(4)  | YES  | MUL | NULL    |       |
+-------+---------+------+-----+---------+-------+
4 rows in set (0.00 sec)


mysql> insert into shipment values(1,1,4, 1);
Query OK, 1 row affected (0.03 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
+------+------+------+------+
1 row in set (0.00 sec)

mysql> insert into shipment values(2,2,4, 1);
Query OK, 1 row affected (0.04 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    2 |    2 |    4 |    1 |
+------+------+------+------+
3 rows in set (0.00 sec)

mysql> update shipment set Pid=3 ,Jid=5 where Pid=2 and QTY=4;
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
+------+------+------+------+
3 rows in set (0.01 sec)

mysql> select * from suplr where Sid in (select Sid from shipment where Jid=1);
+-----+--------+--------+--------+
| Sid | Sname  | Status | City   |
+-----+--------+--------+--------+
|   1 | verma  | good   | pune   |
|   2 | sharma | good   | mumbai |
+-----+--------+--------+--------+
2 rows in set (0.00 sec)

mysql> insert into suplr(Sname, Status, City) values("Mackenzie", "Good", "London")
    -> ;
Query OK, 1 row affected (0.04 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> select * from suplr;
+-----+-----------+--------+------------+
| Sid | Sname     | Status | City       |
+-----+-----------+--------+------------+
|   1 | verma     | good   | pune       |
|   2 | sharma    | good   | mumbai     |
|   3 | kishan    | okay   | ahmednagar |
|   4 | Mackenzie | Good   | London     |
+-----+-----------+--------+------------+
4 rows in set (0.00 sec)

mysql> insert into suplr(Sname, Status, City) values("Queen Elizabeth", "Good", "London");
Query OK, 1 row affected (0.03 sec)

mysql> select * from suplr;
+-----+-----------------+--------+------------+
| Sid | Sname           | Status | City       |
+-----+-----------------+--------+------------+
|   1 | verma           | good   | pune       |
|   2 | sharma          | good   | mumbai     |
|   3 | kishan          | okay   | ahmednagar |
|   4 | Mackenzie       | Good   | London     |
|   5 | Sup liar        | good   | London     |
|   6 | Queen Elizabeth | Good   | London     |
+-----+-----------------+--------+------------+
6 rows in set (0.00 sec)

mysql> desc parts;
+--------+-------------+------+-----+---------+----------------+
| Field  | Type        | Null | Key | Default | Extra          |
+--------+-------------+------+-----+---------+----------------+
| Pid    | int(4)      | NO   | PRI | NULL    | auto_increment |
| Pname  | varchar(20) | YES  |     | NULL    |                |
| Colour | varchar(20) | YES  |     | NULL    |                |
| Weight | varchar(20) | YES  |     | NULL    |                |
| City   | varchar(20) | YES  |     | NULL    |                |
+--------+-------------+------+-----+---------+----------------+
5 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
+------+------+------+------+
3 rows in set (0.00 sec)

mysql> insert into shipment values(1,4,8,4);
Query OK, 1 row affected (0.04 sec)

mysql> insert into shipment values(2,5,2,3);
Query OK, 1 row affected (0.04 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
|    1 |    4 |    8 |    4 |
|    2 |    5 |    2 |    3 |
+------+------+------+------+
5 rows in set (0.01 sec)

mysql> insert into shipment values(1,1,2,3);
Query OK, 1 row affected (0.05 sec)

mysql> select * from shipment;
+------+------+------+------+
| Pid  | Sid  | QTY  | Jid  |
+------+------+------+------+
|    1 |    1 |    4 |    1 |
|    2 |    2 |    7 |    1 |
|    3 |    2 |    4 |    5 |
|    1 |    4 |    8 |    4 |
|    2 |    5 |    2 |    3 |
|    1 |    1 |    2 |    3 |
+------+------+------+------+
6 rows in set (0.00 sec)

mysql> show tables;
+---------------------+
| Tables_in_suppliers |
+---------------------+
| parts               |
| projects            |
| shipment            |
| suplr               |
+---------------------+
4 rows in set (0.00 sec)

mysql> select * from projects where Jid in (select Jid from shipment where Sid=1);
+-----+---------------+--------+
| Jid | Jname         | City   |
+-----+---------------+--------+
|   1 | Drone         | London |
|   3 | Super highway | China  |
+-----+---------------+--------+
2 rows in set (0.00 sec)

mysql> select * from parts;
+-----+-------+--------+--------+--------+
| Pid | Pname | Colour | Weight | City   |
+-----+-------+--------+--------+--------+
|   1 | gear  | black  | 200gms | pune   |
|   2 | axle  | black  | 200gms | mumbai |
|   3 | bolt  | black  | 200gms | mumbai |
+-----+-------+--------+--------+--------+
3 rows in set (0.00 sec)

mysql> select Colour from parts where Pid in (select Pid from shipment where Sid=1);
+--------+
| Colour |
+--------+
| black  |
+--------+
1 row in set (0.00 sec)

mysql> select Pname from parts union select Colour from parts;
+-------+
| Pname |
+-------+
| gear  |
| axle  |
| bolt  |
| black |
+-------+
4 rows in set (0.00 sec)
///////------------------------------------------
mysql> select distinct a.Colour from parts a, shipment b where a.Pid=b.Pid and Sid=1;
+--------+
| Colour |
+--------+
| black  |
| silver |
+--------+
2 rows in set (0.01 sec)

mysql> select distinct a.Colour from parts as a, shipment as b where a.Pid=b.Pid and Sid=1;
+--------+
| Colour |
+--------+
| black  |
| silver |
+--------+
2 rows in set (0.00 sec)
mysql> select p.Pname, q.Colour from parts p cross join parts as q ;
+--------+--------+
| Pname  | Colour |
+--------+--------+
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | black  |
| axle   | black  |
| bolt   | black  |
| wheels | black  |
| gear   | silver |
| axle   | silver |
| bolt   | silver |
| wheels | silver |
+--------+--------+
16 rows in set (0.00 sec)

mysql> select p.Pname, q.City from parts p cross join parts as q ;
+--------+--------+
| Pname  | City   |
+--------+--------+
| gear   | pune   |
| axle   | pune   |
| bolt   | pune   |
| wheels | pune   |
| gear   | mumbai |
| axle   | mumbai |
| bolt   | mumbai |
| wheels | mumbai |
| gear   | mumbai |
| axle   | mumbai |
| bolt   | mumbai |
| wheels | mumbai |
| gear   | Tokyo  |
| axle   | Tokyo  |
| bolt   | Tokyo  |
| wheels | Tokyo  |
+--------+--------+
16 rows in set (0.00 sec)

mysql> 
mysql> select Jid,Sid from shipment group by Sid having count(Sid)>0;
+------+------+
| Jid  | Sid  |
+------+------+
|    1 |    1 |
|    1 |    2 |
|    4 |    4 |
|    3 |    5 |
+------+------+
4 rows in set (0.01 sec)

mysql> select Jid,Sid from shipment group by Sid having count(Sid)>1;
+------+------+
| Jid  | Sid  |
+------+------+
|    1 |    1 |
|    1 |    2 |
+------+------+
2 rows in set (0.00 sec)

*/
