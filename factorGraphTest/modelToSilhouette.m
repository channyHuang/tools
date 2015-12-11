cd 'F:/mycode/Paper_Source_Learning/VisualHull-master'

data_dir = 'dinoSparseRing/'; 
file_base = 'dinoSR';

points3d = load('verts.txt');
points3d = [points3d, ones(size(points3d, 1), 1)];

fid = fopen([data_dir file_base '_par.txt'], 'r');
res = textscan(fid,'%d');
N = res{1,1};
for i=1:N
    textscan(fid,'%s',1);
    res = textscan(fid,'%f', 21);
    tmp =res{1}';
    K = reshape(tmp(1:9), 3, 3)';
    R = reshape(tmp(10:18), 3, 3)';
    t = tmp(19:21)';
    M(:,:,i) = K*[R t];
    
    points2d(:, :, i) = (M(:, :, i) * points3d')';
    %figure;
    %plot3(points2d(:, 1, i),points2d(:, 2, i),ones(size(points2d, 1), 1) );
end
fclose(fid);

