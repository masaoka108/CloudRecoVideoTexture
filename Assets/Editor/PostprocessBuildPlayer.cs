using System.IO;
using UnityEditor;
using UnityEditor.iOS.Xcode;
using UnityEditor.Callbacks;

public class PostprocessBuildPlayer {
	[PostProcessBuildAttribute]
	public static void OnPostprocessBuild(BuildTarget buildTarget, string path) {
		if (buildTarget == BuildTarget.iOS) {
			string projectPath = path + "/Unity-iPhone.xcodeproj/project.pbxproj";
			PBXProject project = new PBXProject();
			project.ReadFromFile(projectPath);

			string target = project.TargetGuidByName("Unity-iPhone");


//			//BitCode をNo
//			project.SetBuildProperty(target, "ENABLE_BITCODE", "NO");
//			project.WriteToFile(projectPath);


			var plistPath = Path.Combine(path, "Info.plist");
			var plist = new PlistDocument();
			plist.ReadFromFile(plistPath);
//			plist.root.SetString("Privacy - Photo Library Usage Description", "Allow access camera roll");
			plist.root.SetString("NSPhotoLibraryUsageDescription", "You can save the photo that is screenshot to the camera roll.if you want,Please allow access camera roll");
			plist.WriteToFile(plistPath);
		}
	}
}