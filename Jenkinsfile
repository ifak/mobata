//Jenkinsfile for automated build generation
//set the variables under "environment" to configure this file. Further changes are not necesarry.
pipeline {
    agent none
	environment {
		//Linux Variables
		QTIFLIN = "/opt/Qt/Tools/QtInstallerFramework/3.0"
		QTDIRLIN = "/opt/Qt/5.9.6/gcc_64"
		LINDIR = "/var/lib/jenkins/workspace/mobata-linux-${env.BRANCH_NAME}"
		LINREPO = "/var/lib/jenkins/workspace/mobata-repository-${env.BRANCH_NAME}"

		//Windows Variables
		//the following windows path variables have to be defined using a double backwards slash "\\"
		QTIFWIN = "C:\\Qt\\Tools\\QtInstallerFramework\\3.0"
		QTDIRWIN64 = "C:\\Qt\\5.9.6\\msvc2015_64"
		VCPATH = '"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC"'directory
		
		//the following windows path variables have to be defined using a single forward slash "/"
		WINREPO = "F:\\Jenkins\\workspace\\mobata-repository-${env.BRANCH_NAME}"
		WIN64DIR = "F:\\Jenkins\\workspace\\mobata_x64_${env.BRANCH_NAME}"

		//The following variables are generated automatically and don't have to be configured:
		WINREPO_FS = "${env.WINREPO}".replaceAll( '\\\\','/')
		WIN32DIR_FS = "${env.WIN32DIR}".replaceAll( '\\\\','/')
		WIN64DIR_FS = "${env.WIN64DIR}".replaceAll( '\\\\','/')
	}
    stages {
        stage('Checkout') {
			steps{
				parallel 'Linux_Debian': { node('Linux_Debian') {
					ws("${env.LINREPO}") {
						checkout scm
					}
				}},
				'Win64': { node('Win10(x64)') {
					ws("${env.WINREPO_FS}") {
						checkout scm
					}
				}}
			}
        }
		stage('Start Build Jobs') { 
			steps {
				parallel 'Linux_Debian': { node('Linux_Debian') {
					build job: 'mobata-linux_x64', parameters: [
						string(name: 'REPOSITORY', value: "${env.LINREPO}"),
						string(name:'BRANCH_NAME', value: "${env.BRANCH_NAME}"),
						string(name:'AUTHORS', value: currentBuild.changeSets[0].collect { it.author }.unique().join(", "))]
				}}
				'Win64': { node('Win10(x64)') {
					build job: 'mobata-win_x64', parameters: [
						string(name: 'REPOSITORY', value: "${env.WINREPO}"),
						string(name:'BRANCH_NAME', value: "${env.BRANCH_NAME}"),
						string(name:'AUTHORS', value: currentBuild.changeSets[0].collect { it.author }.unique().join(", "))]
				}}
			}
        }
    }
}
