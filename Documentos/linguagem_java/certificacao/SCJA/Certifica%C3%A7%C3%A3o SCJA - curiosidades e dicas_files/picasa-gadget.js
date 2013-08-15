function showalbums(json) {

      // this functions reads all albumdata from the json-feed and stores it in array
      var numentries = json.feed.entry.length;
      // main loop gets all the entries from the feed
      for (var i = 0; i < numentries; i++) {
         // get the entry from the feed
         var entry = json.feed.entry[i];

         // get the albumtitle from the entry
         var albumTitle = entry.title.$t;

         // get the album url from the entry
         var albumUrl;
         for (var k = 0; k < entry.link.length; k++) {
            if (entry.link[k].rel == 'alternate') {
            albumUrl = entry.link[k].href;
            break;
            }
         }

         // get the album thumbnail from the entry
         var albumThumbnail = entry.media$group.media$thumbnail[0].url;

         document.write('<a href="' + albumUrl + '" title="Click to view this image" target="_blank"><img src="' + albumThumbnail + ' alt="' + albumTitle + '" /></a>');

      }
   } // end of showalbums
