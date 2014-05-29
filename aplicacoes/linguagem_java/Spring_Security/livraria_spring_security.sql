-- MySQL dump 10.13  Distrib 5.5.29, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: livraria
-- ------------------------------------------------------
-- Server version	5.5.29-0ubuntu0.12.10.1-log

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
-- Current Database: `livraria`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `livraria` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `livraria`;

--
-- Table structure for table `Autorizacao`
--

DROP TABLE IF EXISTS `Autorizacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Autorizacao` (
  `nome` varchar(255) NOT NULL,
  PRIMARY KEY (`nome`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Autorizacao`
--

LOCK TABLES `Autorizacao` WRITE;
/*!40000 ALTER TABLE `Autorizacao` DISABLE KEYS */;
INSERT INTO `Autorizacao` VALUES ('ROLE_ADMIN');
/*!40000 ALTER TABLE `Autorizacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Livro`
--

DROP TABLE IF EXISTS `Livro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Livro` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `autor` varchar(255) DEFAULT NULL,
  `avaliacao` int(11) NOT NULL,
  `editora` varchar(255) DEFAULT NULL,
  `isbn` varchar(255) DEFAULT NULL,
  `paginas` int(11) NOT NULL,
  `titulo` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Livro`
--

LOCK TABLES `Livro` WRITE;
/*!40000 ALTER TABLE `Livro` DISABLE KEYS */;
INSERT INTO `Livro` VALUES (1,'clarice Linspector',2,'Abril','85748',320,'Borboletas'),(2,'Brian Adams',3,'Pearson Education','74859',415,'O vendedor de Ilusoes ');
/*!40000 ALTER TABLE `Livro` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuario`
--

DROP TABLE IF EXISTS `Usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Usuario` (
  `username` varchar(255) NOT NULL,
  `enable` tinyint(1) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuario`
--

LOCK TABLES `Usuario` WRITE;
/*!40000 ALTER TABLE `Usuario` DISABLE KEYS */;
INSERT INTO `Usuario` VALUES ('Leandro',1,'okto2647');
/*!40000 ALTER TABLE `Usuario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuario_Autorizacao`
--

DROP TABLE IF EXISTS `Usuario_Autorizacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Usuario_Autorizacao` (
  `Usuario_username` varchar(255) NOT NULL,
  `autorizacoes_nome` varchar(255) NOT NULL,
  UNIQUE KEY `autorizacoes_nome` (`autorizacoes_nome`),
  KEY `FKD04AA31379DDB250` (`autorizacoes_nome`),
  KEY `FKD04AA3139FEF07F0` (`Usuario_username`),
  CONSTRAINT `FKD04AA31379DDB250` FOREIGN KEY (`autorizacoes_nome`) REFERENCES `Autorizacao` (`nome`),
  CONSTRAINT `FKD04AA3139FEF07F0` FOREIGN KEY (`Usuario_username`) REFERENCES `Usuario` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuario_Autorizacao`
--

LOCK TABLES `Usuario_Autorizacao` WRITE;
/*!40000 ALTER TABLE `Usuario_Autorizacao` DISABLE KEYS */;
INSERT INTO `Usuario_Autorizacao` VALUES ('Leandro','ROLE_ADMIN');
/*!40000 ALTER TABLE `Usuario_Autorizacao` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-05-29 14:47:16
