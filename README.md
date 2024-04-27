## Computer Graphics Assingments

# Ubuntu Requirements 

'''shell
sudo apt install vulkan-tools
sudo apt install libvulkan-dev
sudo apt install vulkan-validationlayers-dev spirv-tools
'''

Test the command:

'''shell
vkcube
'''
If it works continue with the requirements installation.


'''shell
sudo apt install libglfw3-dev
sudo apt install libglm-dev
'''
Now, you need a shader compiler: Glsl from Google is the one I've used.

So, download Google's [unofficial binaries](https://github.com/google/shaderc/blob/main/downloads.md) and copy glslc to your /usr/local/bin. Note you may need to sudo depending on your permissions.

To test, run glslc and it should rightfully complain we didn't pass any shaders to compile:

glslc: error: no input files

