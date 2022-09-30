# CompPhysNumpyExamples

**IMPORTANT: READ THESE INSTRUCTIONS.**

Here you will exercise a few advanced python skills, using `jupyter` notebooks: 

- Problem 1: Array programming and selections. 
- Problem 2: Array programming operations and plotting. 
- Problem 3 (grad students only): using C++ and python with SWIG


## Setup the software 
To perform Problem 3, you will need to have this package **in a parallel directory** to the standard CompPhys package. 


Assuming your folder where you work is called `/home/yourusername/working` 
(and has the contents `results` and `CompPhys`): 

**On your host OS** (that is, your laptop... not the docker image):
```
cd /home/yourusername/working/            #<-- Put in YOUR path to YOUR results folder
git clone https://github.com/ubsuny/CompPhys.git
git clone git@github.com:ubsuny/technical-assignment-3-YOURUSERNAMEGOESHERE.git
```

For your assignment **replace the last line** with your assignment 3 github area. Here is mine (yours is different): 
```
git clone git@github.com:ubsuny/technical-assignment-3-rappoccio-1.git
```

Then, you go to your "working" folder and start the docker container. 

For Mac and Unix users,
```
./CompPhys/runDocker ubsuny/compphys:latest
```

or, if you're in Windows, cut and paste the command from `runDockerWindows.sh` as usual: 

```
docker run --rm -it -v ${PWD}:/home/users/compphys/CompPhys -w /home/users/compphys --entrypoint "/bin/bash" -p 8888:8888 ubsuny/compphys:latest
```

Then you should be in your docker container, so start a jupyter notebook with 

```
jupyter notebook --ip 0.0.0.0 --no-browser
```

## Perform the exercises. 

Then go to [your browser window](http://127.0.0.1:8888) and you should have access to the various problems. 


## Commit your code for the assignment

Go to your assignment directory (mine is below, yours will be different). 
```
cd /home/yourusername/working/technical-assignment-3-rappoccio-1
git add -u . 
git add (whatever other files you need)
git commit -m "I hope I passed"
git push origin main
```

