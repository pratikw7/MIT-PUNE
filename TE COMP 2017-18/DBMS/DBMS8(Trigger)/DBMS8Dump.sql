-- MySQL dump 10.13  Distrib 5.5.54, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: Library
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
-- Table structure for table `Library`
--

DROP TABLE IF EXISTS `Library`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Library` (
  `Bid` int(4) NOT NULL AUTO_INCREMENT,
  `BName` varchar(225) DEFAULT NULL,
  `IssuedOn` datetime DEFAULT NULL,
  `ReturnedOn` datetime DEFAULT NULL,
  PRIMARY KEY (`Bid`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Library`
--

LOCK TABLES `Library` WRITE;
/*!40000 ALTER TABLE `Library` DISABLE KEYS */;
/*!40000 ALTER TABLE `Library` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`blah`@`%`*/ /*!50003 trigger updatebeforetrig before update on Library for each row begin insert into Library_Audit set  Bname=new.BName, IssuedOn=new.IssuedOn, ReturnedOn=now();end */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger deletebeforeTrigger before delete on Library for each row insert into Library_Audit set BName=old.BName, IssuedOn=old.IssuedOn, ReturnedOn=old.ReturnedOn */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `Library_Audit`
--

DROP TABLE IF EXISTS `Library_Audit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Library_Audit` (
  `Bid` int(4) NOT NULL AUTO_INCREMENT,
  `BName` varchar(225) DEFAULT NULL,
  `IssuedOn` datetime DEFAULT NULL,
  `ReturnedOn` datetime DEFAULT NULL,
  PRIMARY KEY (`Bid`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Library_Audit`
--

LOCK TABLES `Library_Audit` WRITE;
/*!40000 ALTER TABLE `Library_Audit` DISABLE KEYS */;
INSERT INTO `Library_Audit` VALUES (1,'Sherlock Holmes','2017-07-28 12:00:00','2017-07-28 12:11:20'),(2,'Hound of Baskervills','2017-07-28 12:00:00','2017-07-28 12:13:55'),(3,'Study in  Scarlet','2017-07-28 12:00:00','2017-07-28 12:17:47'),(4,'Study in  Scarlet','2017-07-28 12:00:00','2017-07-28 12:17:47'),(5,'The Resident Patient','2017-07-28 12:00:00','2017-07-28 12:19:57'),(6,'The Empty House','2017-07-28 12:00:00','2017-07-28 12:19:57'),(7,'The Resident Patient','2017-07-28 12:00:00',NULL);
/*!40000 ALTER TABLE `Library_Audit` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-07-28 12:27:53
