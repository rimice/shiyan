#!/bin/bash

#------------------------------------------
# File name: Mango_release.sh
# Copyright 2013 Wistron
# Description: This file is used to get Mango source code,build new image and zip image
# Author/Ceate date: Allan Xing May23'2013
# Modify history:
#       Allan Xing May24'2013
#       1. change date format to make a distinction between old image folder and new one which build in one day.
#       Allan Xing May29'2013
#       2. revert date change and add judgement for image file exists or not. 
#          modify prompt message 
# Version: v1.2
#-----------------------------------------

#---------------------------------++project forder
	Date=$(date +%Y%m%d)
	RELEASE_ROOT_DIR=$(pwd)
	RELEASE_BSP_DIR=$RELEASE_ROOT_DIR/Mango_project
	BSP_ROOT_DIR=${RELEASE_BSP_DIR}/Mango_bsp
	BSP_DIR=${BSP_ROOT_DIR}/Mango
	IMAGE_DIR=$RELEASE_BSP_DIR/Mango_release_image
	OUT_IMAGE_DIR=${IMAGE_DIR}/${Date}_image

# -------------------------------------------------
# Function Name: clone_for_build()
# Description: git clone source code for build image
# paraments: N/A
# return value: N/A
# Notes: N/A
function clone_for_build()
{
cd $RELEASE_BSP_DIR
if [ ! -d "${BSP_ROOT_DIR}" ];then
	mkdir "${BSP_ROOT_DIR}"
else
	echo "======>${BSP_ROOT_DIR} exists"
fi
cd ${BSP_ROOT_DIR}
	git clone ssh://nts01.wistron.com/Mango.git
	sync
}
# --------------------------------------------- end


# --------------------------------------------
# Function Name: image_build()
# Description: build image
# Paraments: N/A
# Return value: N/A
# Notes: N/A
function image_checkout()
{
cd $BSP_DIR
	BRANCH=origin/alps_mwf_jb2_1.2
	git checkout $BRANCH
	sync
	git log -1 > ${BSP_ROOT_DIR}/gitlog.txt

}
# --------------------------------------------- end

# ---------------------------------------------
# Function Name: version_set()
# Description: set image version
# Paraments: iamge version 
# Return value: N/A
# Notes: N/A
function image_build()
{

	cd $BSP_DIR/alps
	./mk -t wistron89_tb_mwf_jb2 new

}
# --------------------------------------------- end


# ----------------------------------------------
# Function Name: get_iamge()
# Description: get the image files and pack that
# Parameters: N/A
# Return value: N/A
# Notes: N/A
function get_image()
{
    if [ ! -d "$IMAGE_DIR" ];then
        mkdir "$IMAGE_DIR"
    fi
	if [ ! -d "${OUT_IMAGE_DIR}" ];then
		mkdir "${OUT_IMAGE_DIR}"
	else
		echo "======>${OUT_IMAGE_DIR} exists, will delete it ..."
		rm -r ${OUT_IMAGE_DIR}
		mkdir ${OUT_IMAGE_DIR}
	fi
	
	cd ${BSP_DIR}/alps/out/target/product/wistron89_tb_mwf_jb2
	cp *.txt *.img *.mk EBR* *.ini kernel *.bin MBR ${OUT_IMAGE_DIR}
	cd ${IMAGE_DIR}

    version=`grep "MTK_BUILD_VERNO" $BSP_DIR/alps/mediatek/config/common/ProjectConfig.mk | awk -F"[=] " '{if(NR==1)print $2}'`
    if [ -f ${Date}$version.zip ];then
        rm ${Date}$version.zip
    fi
    mv ${Date}_image ${Date}$version
	zip -r ${Date}$version.zip ${Date}$version
	
}
# --------------------------------------------- end


#------------------------------------------- main entry


if [ ! -d "Mango_project" ];then
	mkdir "Mango_project"
else
	echo "======>Mango_project exists, go on doing next..."
	echo "======>clean for new build environment,please waiting..."
	rm -rf Mango_project/Mango_bsp
fi
clone_for_build 	# git clone source code

image_checkout  	# select iamge type (WIFI or 3G)

image_build     	# build Mango image

get_image   		# get Mango image file and pack it


