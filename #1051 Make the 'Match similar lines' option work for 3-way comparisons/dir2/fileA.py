import SetVersions
import ConfigParser

class settings:
    def __init__(self):
        self.rootpath = ''
        self.svn_binary = r'C:\Program Files\Subversion\bin\svn.exe'
        self.vs_path = ''
        self.vs_path7 = r'C:\Program Files\Microsoft Visual Studio .NET 2003'
        self.vs_path8 = r'C:\Program Files\Microsoft Visual Studio 8.0'
        self.vs_path9 = r'C:\Program Files\Microsoft Visual Studio 9.0'
        self.innosetup_path = r'C:\Program Files\Inno Setup 5'
        self.winmerge_iss = 'WinMerge.iss' #filename only
        self.winmerge_iss_path = 'WinMerge.iss' #including path
        self.source = 'workspace'
        self.version = ''
        self.vs_version = 2003

    def create_ini(self, filename):
        config = ConfigParser.RawConfigParser()
        sect = 'RUNTIME'
        if os.path.exists('Tools.ini'):
            config.readfp(open(filename))
        if not config.has_section(sect):
            config.add_section(sect)
        if not config.has_option(sect, 'type'):
            config.set(sect, 'type', 'VSXXXX')
        if not config.has_option(sect, 'VSStudio'):
            config.set(sect, 'VSStudio', self.vs_version)
        if not config.has_option(sect, 'Source'):
            config.set(sect, 'Source', self.source)
        if not config.has_option(sect, 'svn_binary'):
            config.set(sect, 'svn_binary', self.svn_binary)
        if not config.has_option(sect, 'vs_path7'):
            config.set(sect, 'vs_path7', self.vs_path7)
        if not config.has_option(sect, 'vs_path8'):
            config.set(sect, 'vs_path8', self.vs_path8)
        if not config.has_option(sect, 'vs_path9'):
            config.set(sect, 'vs_path9', self.vs_path9)
        if not config.has_option(sect, 'innosetup_path'):
            config.set(sect, 'innosetup_path', self.innosetup_path)

        # Writing our configuration file to 'Tools.ini'
        with open(filename, 'w') as configfile:
            config.write(configfile)

    def read_ini(self, filename):
        config = ConfigParser.RawConfigParser()
        if not os.path.exists(filename):
            # If the config file didn't exist, we create a new file and ask
            # user to edit the config and re-run the script. This is because
            # our defaults probably don't match user's environment.
            self.create_ini(filename)
            print 'New configuration file created: ' + filename
            print 'Please edit the file to match your configuration and re-run the script.'
            sys.exit()

        config.readfp(open(filename))
        self.svn_binary = config.get('RUNTIME', 'svn_binary')
        self.vs_path7 = config.get('RUNTIME', 'vs_path7')
        self.vs_path8 = config.get('RUNTIME', 'vs_path8')
        self.vs_path9 = config.get('RUNTIME', 'vs_path9')
        self.innosetup_path = config.get('RUNTIME', 'innosetup_path')
        self.source = config.get('RUNTIME', 'Source') 
        self.vs_version = config.getint('RUNTIME', 'VSStudio')

        if self.vs_version ==2003:
            self.vs_path =self.vs_path7
        elif self.vs_version ==2005:
            self.vs_path =self.vs_path8
        elif self.vs_version ==2008:
            self.vs_path =self.vs_path9

# global settings class instance
prog = settings()
