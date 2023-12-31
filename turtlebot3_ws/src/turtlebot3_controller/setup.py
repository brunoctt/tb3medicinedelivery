from setuptools import find_packages, setup

package_name = 'turtlebot3_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='bctat',
    maintainer_email='bctat@softex.cin.ufpe.br',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "main_node = turtlebot3_controller.main:main",
            "image_node = turtlebot3_controller.turtlebot3_image_processor:main"                
        ],
    },
)
