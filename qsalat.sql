CREATE TABLE audio (id integer, athan string, fajr string, dua string, playAthan integer, playDua integer);
CREATE TABLE calculation (id integer, method integer, fajr integer, duhr integer, asr integer, hijri integer, higherLat integer);
CREATE TABLE location (id integer, latitude float, longitude float, country string, city string, timezone integer);
INSERT INTO audio 
VALUES ('1','/home/nour/Development/Qsalat/audio/athan.mp4',
        '/home/nour/Development/Qsalat/audio/athanFajr.mp4',
        '/home/nour/Development/Qsalat/audio/dua.mp4',
        '1',
        '1');
        
INSERT INTO calculation VALUES ('1','2','0','0','0','0','0');

INSERT INTO location VALUES ('1','45.5454','-73.6391','Canada','Montreal','-4');
