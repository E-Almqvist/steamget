# steamget :: Efficient way to download addons from the workshop
*Disclaimer: This is still a work in progress! It compiles, I think... But it does not work.*

Steamget is a simple and easy to use binary that downloads addons directly from the Steam workshop using the [Steamworks API](https://partner.steamgames.com/).
This was primarely created for Garry's Mod addons, so do not be surprised if it does not work well with other games on Steam. 


### Installation
Currently there is no installation script or a package so for now you will have to create a Makefile using [cmake](https://cmake.org/) with the [CMakeLists.txt](https://github.com/E-Almqvist/steamget/blob/master/src/CMakeLists.txt) and then compile it yourself. 
#### For lazy people
	git clone https://github.com/E-Almqvist/steamget.git; cd steamget; mkdir bin; cmake ../src; make

### Usage
	steamget -i {fileid} -o {outpath = './'}
	
	fileid [-i]:
		The fileid for the addon. Can be found at the end of the addons workshop url.
		Example: https://steamcommunity.com/sharedfiles/filedetails/?id=107455292 <- there
	
	outpath [-o]:
		Where the addon will be installed. Default is current working directory.
		
### Dependencies
- [C++ Requests: Curl for People](https://github.com/whoshuu/cpr)
- [JSON Parser](https://github.com/nlohmann/json) 
