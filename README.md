```markdown
# Compteri Project

## Vue d'ensemble

Le projet **Compteri** a été développé dans le cadre de l'architecture IoT pour créer un système intelligent de gestion des compteurs d'eau. L'objectif est de réduire la consommation d'eau à l'aide de la technologie IoT, avec des fonctionnalités telles que la détection de pics de consommation, la lecture des compteurs à distance et la gestion des paiements.

### Développé par :
- **Chouaib Saad**  
  [LinkedIn](https://www.linkedin.com/in/chouaib-saad-bb4106219/)  
  Étudiant en systèmes embarqués et IoT

### Sous la supervision de :
- **Amira Henaien**  
  Professeur Assistant en Informatique  
  [Institut Supérieur des Sciences de l'Informatique Mahdia (ISIMA)](https://isima.rnu.tn/fra/home)  
  Université de Monastir, Tunisie

---

## Titre du projet
**Compteri : Système intelligent de gestion des compteurs d'eau**

## Description du projet
Le but du projet est de fournir un moyen intelligent et connecté pour gérer la consommation d'eau à distance grâce à la technologie IoT. Il comprend plusieurs fonctionnalités :
- Calcul de la consommation, détection de pics et projection de la tarification mensuelle.
- Création d'un objet connecté permettant la lecture du compteur.
- Agent intelligent pour la reconnaissance des caractères sur les images (OCR).
- Alerte en cas de fuites ou de consommation anormale.
- Module de paiement à distance pour éviter les files d'attente.

---

## Matériel nécessaire

### Modules principaux :
- **ESP32-CAM Module**  
  ![ESP32-CAM](https://user-images.githubusercontent.com/106425884/209489181-06fce8cf-c6a2-43c4-96e8-3ebde009d16f.jpg)

- **ESP32 Module**  
  ![ESP32 Module](https://user-images.githubusercontent.com/106425884/209489196-016231f0-73d0-480d-b7e3-cb623f3e8a24.jpg)

- **Raspberry Pi 4** (ou un ordinateur portable)  
  ![Raspberry Pi](https://user-images.githubusercontent.com/106425884/209489201-702fc9c4-ccac-484b-bc94-728e968df215.jpg)

### Matériel optionnel (pour le système de sécurité) :
- **PIR Sensor**  
  ![PIR Sensor](https://user-images.githubusercontent.com/106425884/209489241-6426a0bc-49d7-4619-a44c-db60e4ac4a19.jpg)

- **Câbles Jumper**  
  ![Jumper Wires](https://user-images.githubusercontent.com/106425884/209489223-143ffd82-a10c-4d82-9035-2729156682b3.png)

- **Serrure électronique**  
  ![Electronic Door Lock](https://user-images.githubusercontent.com/106425884/209489048-caf90bea-7eb2-4f76-8927-cdf57a904c61.jpg)

---

## Guide d'installation

### 1. **Installer l'application mobile**
Téléchargez et installez l'**application Compteri** sur votre appareil mobile.

---

### 2. **Installer le firmware sur l'ESP32-CAM**
#### Étapes :
1. Fixez la position de la caméra à l'aide du sketch de streaming vidéo.
2. Installez **Python** depuis le Microsoft Store.
3. Téléchargez et décompressez le firmware depuis GitHub.
4. Copiez les fichiers du dossier `sdcard` sur une carte microSD (16GB minimum, formatée en FAT32).
5. Modifiez le fichier `wlan.ini` pour y entrer vos informations Wi-Fi.
6. Connectez l'ESP32-CAM à votre ordinateur et insérez la carte microSD préparée.

#### Installer les bibliothèques Python
Dans **Command Line** ou **PowerShell**, exécutez :
```bash
sudo apt-get install python3-pip
sudo pip install esptool
```

#### Flasher l'ESP32-CAM
Accédez au dossier du firmware et exécutez les commandes suivantes :
```bash
esptool.py.exe erase_flash
esptool.py.exe write_flash 0x01000 bootloader.bin 0x08000 partitions.bin 0x10000 firmware.bin
```
Le firmware devrait maintenant être installé avec succès.

**Note :** Si vous rencontrez des erreurs, vérifiez l'installation avec :
```bash
pip show -f esptool
```

---

### 3. **Uploader le module de sécurité sur l'ESP32**
Ouvrez le fichier `code module de securite esp32.ino` dans l'IDE Arduino, puis téléversez-le sur l'ESP32 à l'aide d'un câble micro-USB.

---

### 4. **Installer le broker MQTT sur Raspberry Pi**
1. Installez **Mosquitto** en suivant les instructions sur le [site officiel](https://mosquitto.org/download/).
2. Lancez le serveur Mosquitto avec les commandes suivantes :
   ```bash
   cd C:\Program Files\mosquitto
   mosquitto -v -c test.conf
   ```
3. Abonnez-vous au serveur avec la commande suivante :
   ```bash
   mosquitto_sub -h <Votre IP> -t compteur/coutMesuree -d
   ```

---

## Configuration & Connexions

### 1. **Modèle Carton du Compteri**
Utilisez un modèle carton pour l'assemblage physique du système.
![Carton Model](https://user-images.githubusercontent.com/106425884/209491827-d3394bc7-1f32-452d-b5f4-4c80700ba7eb.jpg)

### 2. **Impression 3D recommandée**
Pour une meilleure expérience, il est conseillé d'imprimer les composants en 3D.
![3D Printed Model](https://user-images.githubusercontent.com/106425884/209492126-9c536493-1ad6-49ca-91e9-6a30c310729c.jpg)

### 3. **Schémas de câblage ESP32-CAM**
- **Méthode 1 :**  
  ![Method 1](https://user-images.githubusercontent.com/106425884/209492564-bc6d91ce-f0bc-441d-b5c2-cc620b95d539.png)

- **Méthode 2 :**  
  ![Method 2](https://user-images.githubusercontent.com/106425884/209493542-79aa86db-877d-4be7-8b9b-225dc965c661.png)

### 4. **ESP32 + Serrure Électronique**
![ESP32 + Door Lock](https://user-images.githubusercontent.com/106425884/209493609-e3ca9d7c-c2be-4968-a684-f74563e424ce.jpg)

### 5. **ESP32 + Capteur PIR**
![ESP32 + PIR Sensor](https://user-images.githubusercontent.com/106425884/209493633-73fb1de8-95a0-4fa9-957b-46d89f792021.jpg)

---

## Félicitations ! Votre projet est prêt à être utilisé. 🎉

### 1. **Dashboard**
![Dashboard](https://user-images.githubusercontent.com/106425884/209493813-6b28c5d2-ac5c-473d-9261-68c5ff9ce15d.jpg)

### 2. **Démo de l'application mobile**
[Voir la démo de l'application mobile](https://user-images.githubusercontent.com/106425884/209493831-5853e501-bccb-4adf-a828-69d4fe39999a.mp4)

---

```
